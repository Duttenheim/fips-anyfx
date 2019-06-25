//------------------------------------------------------------------------------
//  shadercompilerapp.cc
//  (C) 2019 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------

#include "shadercompilerapp.h"
#include "argh.h"
#include <filesystem>


//------------------------------------------------------------------------------
/**
*/
bool
ShaderCompilerApp::ParseCmdLineArgs(const char ** argv)
{
	argh::parser args;
	args.add_params({ "-i", "-o", "-h" });
	args.parse(argv);

	this->shaderCompiler.SetDebugFlag(args["debug"]);
	std::string buffer;	
	if (!(args("o") >> buffer))
	{
		fprintf(stderr, "anyfxcompiler error: no output specified\n");
		return false;
	}

    this->shaderCompiler.SetDstDir(buffer);

	if (!(args("i") >> buffer))
	{
		fprintf(stderr, "anyfxcompiler error: no input file specified\n");
		return false;
	}
	this->src = buffer;
	if (args("h") >> buffer)
	{
		this->shaderCompiler.SetHeaderDir(buffer);
	}

    // find include dir args
	
	const std::vector<std::string> &allargs = args.args();

    for (int i = 0; i < allargs.size(); i++)
    {
         if (allargs[i] == "-I" && i+1 < allargs.size())
         {
			 this->shaderCompiler.AddIncludeDir(allargs[++i]);
         }
    }
        
	this->mode = args["M"];
            
    return true;
}



//------------------------------------------------------------------------------
/**
*/
void
ShaderCompilerApp::Run()
{   
	bool success = false;
            
    if(this->mode)
    {
        success = this->shaderCompiler.CreateDependencies(this->src);
    }
    else
    {
        success = this->shaderCompiler.CompileShader(this->src);
    }       
}


//------------------------------------------------------------------------------
/**
*/
int __cdecl
main(int argc, const char** argv)
{
	ShaderCompilerApp app;
	
	app.ParseCmdLineArgs(argv);
	app.Run();

}
