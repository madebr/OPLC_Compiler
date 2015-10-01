using namespace std;

#include <string.h>

#include "oplc_compiler.h"

// I/O that we have seen recently, so that we don't forget pin assignments
// when we re-extract the list
#define MAX_IO_SEEN_PREVIOUSLY 512
static struct {
    char    name[MAX_NAME_LEN];
    int     type;
    int     pin;
} IoSeenPreviously[MAX_IO_SEEN_PREVIOUSLY];
static int IoSeenPreviouslyCount;


int GenerateIoList(int prevSel)
{
	return 0;
}

//-----------------------------------------------------------------------------
// Move an I/O pin into the `seen previously' list. This means that if the
// user creates input Xasd, assigns it a pin, deletes, and then recreates it,
// then it will come back with the correct pin assigned.
//-----------------------------------------------------------------------------
static void AppendIoSeenPreviously(char *name, int type, int pin)
{
    if(strcmp(name+1, "new")==0) return;

    int i;
    for(i = 0; i < IoSeenPreviouslyCount; i++)
    {
        if(strcmp(name, IoSeenPreviously[i].name)==0 && type == IoSeenPreviously[i].type)
        {
            if(pin != NO_PIN_ASSIGNED)
            {
                IoSeenPreviously[i].pin = pin;
            }
            return;
        }
    }
    if(IoSeenPreviouslyCount >= MAX_IO_SEEN_PREVIOUSLY)
    {
        // maybe improve later; just throw away all our old information, and
        // the user might have to reenter the pin if they delete and recreate
        // things
        IoSeenPreviouslyCount = 0;
    }

    i = IoSeenPreviouslyCount;
    IoSeenPreviously[i].type = type;
    IoSeenPreviously[i].pin = pin;
    strcpy(IoSeenPreviously[i].name, name);
    IoSeenPreviouslyCount++;
}

//-----------------------------------------------------------------------------
// Load the I/O list from a file. Since we are just loading pin assignments,
// put it into IoSeenPreviously so that it will get used on the next
// extraction.
//-----------------------------------------------------------------------------
BOOL LoadIoListFromFile(FILE *f)
{
    char line[80];
    char name[MAX_NAME_LEN];
    int pin;
    while(fgets(line, sizeof(line), f))
    {
        if(strcmp(line, "END\n")==0)
        {
            return TRUE;
        }
        // Don't internationalize this! It's the file format, not UI.
        if(sscanf(line, "    %s at %d", name, &pin)==2)
        {
            int type;
            switch(name[0])
            {
                case 'X': type = IO_TYPE_DIG_INPUT; break;
                case 'Y': type = IO_TYPE_DIG_OUTPUT; break;
                case 'A': type = IO_TYPE_READ_ADC; break;
                default: oops();
            }
            AppendIoSeenPreviously(name, type, pin);
        }
    }
    return FALSE;
}
