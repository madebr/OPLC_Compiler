using namespace std;

#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "oplc_compiler.h"

char CurrentSaveFile[MAX_PATH];
static BOOL ProgramChangedNotSaved = FALSE;
char CurrentCompileFile[MAX_PATH];

// Everything relating to the PLC's program, I/O configuration, processor
// choice, and so on--basically everything that would be saved in the
// project file.
PlcProgram Prog;


int main(int argc, char* argv[])
{
	char *err = "Bad command line arguments: run 'oplc_compiler src.ld dest.cpp'";
	if (argc < 3) { Error(err); exit(-1); }

	char *source = argv[1];
	char *dest = argv[2];

	if(!LoadProjectFromFile(source))
	{
		Error("Couldn't open file");
		exit(-1);
	}

	strcpy(CurrentCompileFile, dest);
	GenerateIoList(-1);
	CompileProgram(FALSE);
	exit(0);
}

static void CompileProgram(BOOL compileAs)
{

}
