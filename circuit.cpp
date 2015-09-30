using namespace std;

#include <stddef.h>
#include <stdlib.h>

#include "oplc_compiler.h"


//-----------------------------------------------------------------------------
// Free a circuit and all of its subcircuits. Calls self recursively to do
// so.
//-----------------------------------------------------------------------------
void FreeCircuit(int which, void *any)
{
    ok();
    switch(which) {
        case ELEM_SERIES_SUBCKT: {
            ElemSubcktSeries *s = (ElemSubcktSeries *)any;
            int i;
            for(i = 0; i < s->count; i++) {
                FreeCircuit(s->contents[i].which, s->contents[i].d.any);
            }
            CheckFree(s);
            break;
        }
        case ELEM_PARALLEL_SUBCKT: {
            ElemSubcktParallel *p = (ElemSubcktParallel *)any;
            int i;
            for(i = 0; i < p->count; i++) {
                FreeCircuit(p->contents[i].which, p->contents[i].d.any);
            }
            CheckFree(p);
            break;
        }
        CASE_LEAF
            ForgetFromGrid(any);
            CheckFree(any);
            break;

        default:
            oops();
            break;
    }
    ok();
}

//-----------------------------------------------------------------------------
// Free the entire program.
//-----------------------------------------------------------------------------
void FreeEntireProgram(void)
{
    ForgetEverything();

    int i;
    for(i = 0; i < Prog.numRungs; i++) {
        FreeCircuit(ELEM_SERIES_SUBCKT, Prog.rungs[i]);
    }
    Prog.numRungs = 0;
    Prog.cycleTime = 10000;
    Prog.mcuClock = 4000000;
    Prog.baudRate = 2400;
    Prog.io.count = 0;
    Prog.mcu = NULL;
}
