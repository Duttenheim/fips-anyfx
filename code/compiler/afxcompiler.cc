//------------------------------------------------------------------------------
/**
    AnyFX compiler functions
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "cmdlineargs.h"
#include "afxcompiler.h"
#include "v3/compiler.h"
#include "v3/ast/effect.h"
#include <fstream>
#include <algorithm>
#include <locale>
#include <iostream>

#include "antlr4-runtime.h"
#include "antlr4-common.h"
#include "parser4/AnyFXLexer.h"
#include "parser4/AnyFXParser.h"
#include "parser4/AnyFXBaseListener.h"
#include "parser4/anyfxerrorhandlers.h"

using namespace antlr4;

#include "mcpp_lib.h"
#include "mcpp_out.h"
#include "glslang/Public/ShaderLang.h"

//------------------------------------------------------------------------------
/**
*/
bool
AnyFXPreprocess(const std::string& file, const std::vector<std::string>& defines, const std::string& vendor, std::string& output)
{
    std::string fileName = file.substr(file.rfind("/")+1, file.length()-1);
    std::string vend = "-DVENDOR=" + vendor;

    std::string folder = file.substr(0, file.rfind("/")+1);

    const char* constArgs[] =
    {
        "",			// first argument is supposed to be application system path, but is omitted since we run mcpp directly
        "-W 0",
        "-a",
        "-v",
        vend.c_str()
    };
    const unsigned numConstArgs = sizeof(constArgs) / sizeof(char*);
    const unsigned numTotalArgs = numConstArgs + defines.size() + 1;
    const char** args = new const char*[numConstArgs + defines.size() + 1];
    memcpy(args, constArgs, sizeof(constArgs));

    unsigned i;
    for (i = 0; i < defines.size(); i++)
    {
        args[numConstArgs + i] = defines[i].c_str();
    }
    args[numTotalArgs-1] = file.c_str();

    // run preprocessing
    mcpp_use_mem_buffers(1);
    int result = mcpp_lib_main(numTotalArgs, (char**)args);
    if (result != 0)
    {
        delete[] args;
        return false;
    }
    else
    {
        char* preprocessed = mcpp_get_mem_buffer((OUTDEST)0);
        output.append(preprocessed);

        // cleanup mcpp
        mcpp_use_mem_buffers(1);
        delete[] args;
        return true;
    }
}

//------------------------------------------------------------------------------
/**
*/
std::vector<std::string>
AnyFXGenerateDependencies(const std::string& file, const std::vector<std::string>& defines)
{
    std::vector<std::string> res;

    const char* constArgs[] =
    {
        "",			// first argument is supposed to be application system path, but is omitted since we run mcpp directly
        "-M"
    };
    const unsigned numConstArgs = sizeof(constArgs) / sizeof(char*);
    const unsigned numTotalArgs = numConstArgs + defines.size() + 1;
    const char** args = new const char*[numConstArgs + defines.size() + 1];
    memcpy(args, constArgs, sizeof(constArgs));

    unsigned i;
    for (i = 0; i < defines.size(); i++)
    {
        args[numConstArgs + i] = defines[i].c_str();
    }
    args[numTotalArgs - 1] = file.c_str();

    // run preprocessing
    mcpp_use_mem_buffers(1);
    int result = mcpp_lib_main(numTotalArgs, (char**)args);
    if (result == 0)
    {
        std::string output = mcpp_get_mem_buffer((OUTDEST)0);

        // grah, remove the padding and the Makefile stuff, using std::string...
        size_t colon = output.find_first_of(':')+1;
        output = output.substr(colon);
        size_t newline = output.find_first_of('\n');
        while (newline != output.npos)
        {
            std::string line = output.substr(0, newline);
            if (!line.empty())
            {
                while (!line.empty() && (line.front() == ' '))								line = line.substr(1);
                while (!line.empty() && (line.back() == ' ' || line.back() == '\\'))		line = line.substr(0, line.size() - 1);
                res.push_back(line);
                output = output.substr(newline + 1);
                newline = output.find_first_of('\n');
            }
            else
                break;
        }
    }
    delete[] args;

    return res;
}

//------------------------------------------------------------------------------
/**
*/
AnyFXErrorBlob*
Error(const std::string message)
{
    AnyFXErrorBlob* ret = new AnyFXErrorBlob();
    if (message.size() > 0)
    {
        ret->buffer = new char[message.size() + 1];
        ret->size = message.size();
        message.copy(ret->buffer, ret->size);
        ret->buffer[ret->size] = '\0';
    }
    else
    {
        ret->buffer = nullptr;
        ret->size = 0;
    }
    return ret;
}

//------------------------------------------------------------------------------
/**
    Compiles AnyFX effect.

    @param file			Input file to compile
    @param output		Output destination file
    @param target		Target language
    @param vendor		GPU vendor name
    @param defines		List of preprocessor definitions
    @param errorBuffer	Buffer containing errors, created in function but must be deleted manually
*/
bool
AnyFXCompile(const std::string& file, const std::string& output, const std::string& header_output, const std::string& target, const std::string& vendor, const std::vector<std::string>& defines, const std::vector<std::string>& flags, AnyFXErrorBlob*& errorBuffer)
{
    bool ret = true;

    std::string preprocessed;
    errorBuffer = nullptr;

    if (AnyFXPreprocess(file, defines, vendor, preprocessed))
    {
        ANTLRInputStream input;
        input.load(preprocessed);

        AnyFXLexer lexer(&input);
        lexer.setTokenFactory(AnyFXTokenFactory::DEFAULT);
        CommonTokenStream tokens(&lexer);
        AnyFXParser parser(&tokens);

        // get the name of the shader
        std::locale loc;
        size_t extension = file.rfind('.');
        size_t lastFolder = file.rfind('/') + 1;
        std::string effectName = file.substr(lastFolder, (file.length() - lastFolder) - (file.length() - extension));
        effectName[0] = std::toupper(effectName[0], loc);
        size_t undersc = effectName.find('_');
        while (undersc != std::string::npos)
        {
            effectName[undersc + 1] = std::toupper(effectName[undersc + 1], loc);
            effectName = effectName.erase(undersc, 1);
            undersc = effectName.find('_');
        }

        // setup preprocessor
        parser.preprocess();

        // remove all preprocessor crap left by mcpp
        size_t i;
        for (i = 0; i < parser.lines.size(); i++)
        {
            size_t start = std::get<2>(parser.lines[i]);
            size_t stop = preprocessed.find('\n', start);
            std::string fill(stop - start, ' ');
            preprocessed.replace(start, stop - start, fill);
        }

        AnyFXLexerHandler lexerErrorHandler;
        lexerErrorHandler.lines = parser.lines;
        AnyFXParserHandler parserErrorHandler;
        parserErrorHandler.lines = parser.lines;

        // reload the preprocessed data
        input.reset();
        input.load(preprocessed);
        lexer.setInputStream(&input);
        lexer.setTokenFactory(AnyFXTokenFactory::DEFAULT);
        lexer.addErrorListener(&lexerErrorHandler);
        tokens.setTokenSource(&lexer);
        parser.setTokenStream(&tokens);
        parser.addErrorListener(&parserErrorHandler);

        Effect* effect = parser.entry()->returnEffect;

        // if we have any lexer or parser error, return early
        if (lexerErrorHandler.hasError || parserErrorHandler.hasError)
        {
            std::string errorMessage;
            errorMessage.append(lexerErrorHandler.errorBuffer);
            errorMessage.append(parserErrorHandler.errorBuffer);
            errorBuffer = Error(errorMessage);
            return false;
        }

        // setup and run compiler
        BinWriter binaryWriter;
        binaryWriter.SetPath(output);
        TextWriter headerWriter;
        headerWriter.SetPath(header_output);

        Compiler compiler;
        compiler.debugPath = output;
        compiler.debugOutput = true;
        compiler.Setup(Compiler::Language::SPIRV, {}, 1);

        if (compiler.Compile(effect, binaryWriter, headerWriter))
        {
            // success!
            return true;
        }
        else
        {
            // convert error list to string
            std::string err;
            for (size_t i = 0; i < compiler.errors.size(); i++)
            {
                if (i > 0)
                    err.append("\n");
                err.append(compiler.errors[i]);
            }
            if (err.empty())
                err = "PLACEHOLDER COMPILER ERROR";
            errorBuffer = Error(err);
            return false;
        }
    }
    return false;
}

//------------------------------------------------------------------------------
/**
    Run before compilation
*/
void
AnyFXBeginCompile()
{
    glslang::InitializeProcess();
}

//------------------------------------------------------------------------------
/**
    Run after compilation
*/
void
AnyFXEndCompile()
{
    glslang::FinalizeProcess();

}
