using namespace std;

#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "oplc_compiler.h"
#include "mcutable.h"

char CurrentSaveFile[MAX_PATH];
static BOOL ProgramChangedNotSaved = FALSE;
char CurrentCompileFile[MAX_PATH];

// Everything relating to the PLC's program, I/O configuration, processor
// choice, and so on--basically everything that would be saved in the
// project file.
PlcProgram Prog;

//-----------------------------------------------------------------------------
// Compile the program to a cpp file for the target device.
// Call the specific compile routines.
//-----------------------------------------------------------------------------
void CompileAnsiC(char *dummy)
{
	//dummy function
}

static void CompileProgram()
{
	//OpenPLC changes
	Prog.mcu=&SupportedMcus[ISA_ANSIC]; //force the MCU to ANSI C code
	Prog.mcu->whichIsa = ISA_ANSIC;
	Prog.cycleTime = 50000; //force the cycle time to 50ms

    if(!GenerateIntermediateCode()) return;

    if(Prog.mcu == NULL)
    {
        Error("Must choose a target microcontroller before compiling.");
        return;
    }

    if(UartFunctionUsed() && Prog.mcu->uartNeeds.rxPin == 0)
    {
        Error("UART function used but not supported for this micro.");
        return;
    }

    if(PwmFunctionUsed() && Prog.mcu->pwmNeedsPin == 0)
    {
        Error("PWM function used but not supported for this micro.");
        return;
    }

	CompileAnsiC(CurrentCompileFile);
}


int main(int argc, char* argv[])
{
	char *err = "Bad command line arguments: run 'oplc_compiler src.ld dest.cpp'";
	if (argc < 3) { Error(err); exit(-1); }

	char *source = argv[1];
	char *dest = argv[2];

	if(!LoadProjectFromFile(source))
	{
		Error("Couldn't open '%s'", source);
		exit(-1);
	}

	strcpy(CurrentCompileFile, dest);
	GenerateIoList(-1);
	CompileProgram();
	exit(0);
}
