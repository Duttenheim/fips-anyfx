//------------------------------------------------------------------------------
//  shaderc.cc
//  (C) 2018 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "singleshadercompiler.h"
#include <filesystem>
#include "afxcompiler.h"

//------------------------------------------------------------------------------
/**
*/
SingleShaderCompiler::SingleShaderCompiler() :
	language("SPIRV"),        	
	platform("win32"),	
	debug(false),
	quiet(false),
	defaultSet(3)
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
SingleShaderCompiler::~SingleShaderCompiler()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
bool 
SingleShaderCompiler::CompileShader(const std::string& src)
{
	// check if source
	if (!std::filesystem::exists(src))
	{
		fprintf(stderr, "[anyfxcompiler] error: shader source '%s' not found!\n", src.c_str());
		return false;
	}

	// make sure the target directory exists
	if (!this->dstDir.empty())
		std::filesystem::create_directories(this->dstDir + "/shaders");
	if (!this->headerDir.empty())
		std::filesystem::create_directories(this->headerDir);
	
	return this->CompileSPIRV(src);	
}

//------------------------------------------------------------------------------
/**
*/
bool
SingleShaderCompiler::CompileSPIRV(const std::string& src)
{
	// start AnyFX compilation
	AnyFXBeginCompile();

	std::filesystem::path sp(src);
    
	std::string file = sp.stem().string();
    std::string folder = sp.parent_path().string();
	std::string destFile;
	std::string destHeader;
	
	if (this->dstDir.empty())
	{
		if (!this->quiet)
		{
			fprintf(stderr, "[anyfxcompiler] \n Checking for problems:\n   %s\n", src.c_str());
		}
	}
	else
	{
		// format destination
        std::string folderName = "";
        if (!this->rootDir.empty())
            folderName = std::filesystem::relative(sp.parent_path(), this->rootDir).string();
        std::string destFolder = this->dstDir + "/shaders/" + folderName;
        std::filesystem::create_directory(destFolder);
        destFile = std::filesystem::absolute(destFolder + "/" + file + ".fxb").string();

        if (!this->headerDir.empty())
        {
            destFolder = this->headerDir + "/" + folderName;
            std::filesystem::create_directory(destFolder);
            destHeader = std::filesystem::absolute(destFolder + "/" + file + ".h").string();
        }

		std::filesystem::path dest(destFile);

		// compile
		if (!this->quiet)
		{
			fprintf(stderr, "[anyfxcompiler] \n Compiling:\n   %s -> %s", src.c_str(), destFile.c_str());
            if (!this->headerDir.empty())
			    fprintf(stderr,"          \n Generating:\n   %s -> %s\n", src.c_str(), destHeader.c_str());
		}

	}
    
    std::vector<std::string> defines;
    std::vector<std::string> flags;
    std::string define= "-D GLSL";
	defines.push_back(define);

    // first include this folder
	define = "-I" + folder + "/";
    defines.push_back(define);

    for (auto inc : this->includeDirs)
    {
		define = "-I" + inc + "/";
        defines.push_back(define);
    }

    // set flags
    flags.push_back("/NOSUB");			// deactivate subroutine usage, effectively expands all subroutines as functions
    flags.push_back("/GBLOCK");			// put all shader variables outside of an explicit block in one global block
	char buffer[25];
	snprintf(buffer, 25, "/DEFAULTSET %d", this->defaultSet);
    flags.push_back(std::string(buffer));	// since we want the most frequently switched set as high as possible, we send the default set to 8, must match the NEBULAT_DEFAULT_GROUP in std.fxh and DEFAULT_GROUP in coregraphics/config.h
    std::vector<std::pair<unsigned, std::string>> resourceTableNames = {
        std::make_pair(0, "Tick")
        , std::make_pair(1, "Frame")
        , std::make_pair(2, "Pass")
        , std::make_pair(3, "Batch")
        , std::make_pair(4, "Instance")
        , std::make_pair(5, "System")
        , std::make_pair(6, "DynamicOffset")
    };

    // if using debug, output raw shader code
    if (!this->debug)
    {
        flags.push_back("/O");
    }

    AnyFXErrorBlob* errors = NULL;

    // this will get the highest possible value for the GL version, now clamp the minor and major to the one supported by glew
    int major = 1;
    int minor = 0;

    std::string target;
    snprintf(buffer,25,"spv%d%d", major, minor);
	target = buffer;

	std::filesystem::path escapedDst(destFile);
	std::filesystem::path escapedHeader(destHeader);

    bool res = AnyFXCompile(
        sp.string().c_str()
        , escapedDst.string().c_str()
        , escapedHeader.string().c_str()
        , target.c_str()
        , "Khronos"
        , defines
        , flags
        , resourceTableNames
        , &errors);
    if (!res)
    {
        if (errors)
        {
            fprintf(stderr,"%s\n", errors->buffer);
            delete errors;
            errors = 0;
        }
        return false;
    }
    else if (errors)
    {
        fprintf(stderr, "%s\n", errors->buffer);
        delete errors;
        errors = 0;
    }
    // stop AnyFX compilation
    AnyFXEndCompile();
    return true;
}


//------------------------------------------------------------------------------
/**
*/
bool
SingleShaderCompiler::CreateDependencies(const std::string& src)
{

	std::filesystem::path sp(src);
	std::string file = sp.stem().string();
	std::string folder = sp.parent_path().string();

	// format destination
	std::string destFile = this->dstDir + "/shaders/" + file + ".dep";

	// compile
	if (!this->quiet)
	{
		fprintf(stderr, "[anyfxcompiler] \n Analyzing:\n   %s -> %s\n", src.c_str(), destFile.c_str());	
	}

	std::vector<std::string> defines;
	std::vector<std::string> flags;
	std::string define = "-D GLSL";
	defines.push_back(define);

	// first include this folder
	define = "-I" + folder + "/";
	defines.push_back(define);

	for (auto inc : this->includeDirs)
	{
		define = "-I" + inc + "/";
		defines.push_back(define);
	}

	std::filesystem::path destDir(this->dstDir);
	std::filesystem::create_directories(destDir);
#pragma warning (disable:4996)
	FILE * output = fopen(destFile.c_str(), "w");
	if(output)
	{
		std::vector<std::string> deps = AnyFXGenerateDependencies(sp.string().c_str(), defines);
        for(auto str : deps)
        {
			fprintf(output, "%s;", str.c_str());
        }
		fclose(output);
	}
    
    return true;
}
