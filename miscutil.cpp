using namespace std;

#include <iostream>

#include "oplc_compiler.h"

void Error(char *str)
{
	//So far a very simple ERROR function
	cout << str << endl;
}

//-----------------------------------------------------------------------------
// printf-like debug function
//-----------------------------------------------------------------------------
void dbp(char *str, ...)
{

}

//-----------------------------------------------------------------------------
// Check the consistency of the heap on which all the PLC program stuff is
// stored.
//-----------------------------------------------------------------------------
void CheckHeap(char *file, int line)
{

}

//-----------------------------------------------------------------------------
// Like malloc/free, but memsets memory allocated to all zeros. Also TODO some
// checking and something sensible if it fails.
//-----------------------------------------------------------------------------
void *CheckMalloc(size_t n)
{

}
void CheckFree(void *p)
{

}
