/* This is auto-generated code from LDmicro. Do not edit this file! Go
   back to the ladder diagram source for changes in the logic, and make
   any C additions either in ladder.h or in additional .c files linked
   against this one. */

/* You must provide ladder.h; there you must provide:
      * a typedef for SWORD and BOOL, signed 16 bit and boolean types
        (probably typedef signed short SWORD; typedef unsigned char BOOL;)

   You must also provide implementations of all the I/O read/write
   either as inlines in the header file or in another source file. (The
   I/O functions are all declared extern.)

   See the generated source code (below) for function names. */
#include "ladder.h"

/* Define EXTERN_EVERYTHING in ladder.h if you want all symbols extern.
   This could be useful to implement `magic variables,' so that for
   example when you write to the ladder variable duty_cycle, your PLC
   runtime can look at the C variable U_duty_cycle and use that to set
   the PWM duty cycle on the micro. That way you can add support for
   peripherals that LDmicro doesn't know about. */
#ifdef EXTERN_EVERYTHING
#define STATIC 
#else
#define STATIC static
#endif

/* Define NO_PROTOTYPES if you don't want LDmicro to provide prototypes for
   all the I/O functions (Read_U_xxx, Write_U_xxx) that you must provide.
   If you define this then you must provide your own prototypes for these
   functions in ladder.h, or provide definitions (e.g. as inlines or macros)
   for them in ladder.h. */
#ifdef NO_PROTOTYPES
#define PROTO(x)
#else
#define PROTO(x) x
#endif

/* U_xxx symbols correspond to user-defined names. There is such a symbol
   for every internal relay, variable, timer, and so on in the ladder
   program. I_xxx symbols are internally generated. */
STATIC BOOL I_b_mcr = 0;
#define Read_I_b_mcr() I_b_mcr
#define Write_I_b_mcr(x) I_b_mcr = x
STATIC BOOL I_b_rung_top = 0;
#define Read_I_b_rung_top() I_b_rung_top
#define Write_I_b_rung_top(x) I_b_rung_top = x
STATIC BOOL I_b_parOut_0000 = 0;
#define Read_I_b_parOut_0000() I_b_parOut_0000
#define Write_I_b_parOut_0000(x) I_b_parOut_0000 = x
STATIC BOOL I_b_parThis_0000 = 0;
#define Read_I_b_parThis_0000() I_b_parThis_0000
#define Write_I_b_parThis_0000(x) I_b_parThis_0000 = x

/* You provide this function. */
PROTO(extern BOOL Read_U_b_X1_0(void);)


/* You provide these functions. */
PROTO(BOOL Read_U_b_Y1_0(void);)
PROTO(void Write_U_b_Y1_0(BOOL v);)

STATIC BOOL U_b_Rturnoff = 0;
#define Read_U_b_Rturnoff() U_b_Rturnoff
#define Write_U_b_Rturnoff(x) U_b_Rturnoff = x
STATIC BOOL I_b_parOut_0001 = 0;
#define Read_I_b_parOut_0001() I_b_parOut_0001
#define Write_I_b_parOut_0001(x) I_b_parOut_0001 = x
STATIC BOOL I_b_parThis_0001 = 0;
#define Read_I_b_parThis_0001() I_b_parThis_0001
#define Write_I_b_parThis_0001(x) I_b_parThis_0001 = x

/* You provide this function. */
PROTO(extern BOOL Read_U_b_X1_1(void);)


/* You provide this function. */
PROTO(extern BOOL Read_U_b_X3_1(void);)



/* Call this function once per PLC cycle. You are responsible for calling
   it at the interval that you specified in the MCU configuration when you
   generated this code. */
void PlcCycle(void)
{
    Write_I_b_mcr(1);
    
    /* start rung 2 */
    Write_I_b_rung_top(Read_I_b_mcr());
    
    /* start series [ */
    /* start parallel [ */
    Write_I_b_parOut_0000(0);
    Write_I_b_parThis_0000(Read_I_b_rung_top());
    if(!Read_U_b_X1_0()) {
        Write_I_b_parThis_0000(0);
    }
    
    if(Read_I_b_parThis_0000()) {
        Write_I_b_parOut_0000(1);
    }
    Write_I_b_parThis_0000(Read_I_b_rung_top());
    if(!Read_U_b_Y1_0()) {
        Write_I_b_parThis_0000(0);
    }
    
    if(Read_I_b_parThis_0000()) {
        Write_I_b_parOut_0000(1);
    }
    Write_I_b_rung_top(Read_I_b_parOut_0000());
    /* ] finish parallel */
    if(Read_U_b_Rturnoff()) {
        Write_I_b_rung_top(0);
    }
    
    Write_U_b_Y1_0(Read_I_b_rung_top());
    
    /* ] finish series */
    
    /* start rung 4 */
    Write_I_b_rung_top(Read_I_b_mcr());
    
    /* start series [ */
    /* start parallel [ */
    Write_I_b_parOut_0001(0);
    Write_I_b_parThis_0001(Read_I_b_rung_top());
    if(!Read_U_b_X1_1()) {
        Write_I_b_parThis_0001(0);
    }
    
    if(Read_I_b_parThis_0001()) {
        Write_I_b_parOut_0001(1);
    }
    Write_I_b_parThis_0001(Read_I_b_rung_top());
    if(!Read_U_b_X3_1()) {
        Write_I_b_parThis_0001(0);
    }
    
    if(Read_I_b_parThis_0001()) {
        Write_I_b_parOut_0001(1);
    }
    Write_I_b_rung_top(Read_I_b_parOut_0001());
    /* ] finish parallel */
    Write_U_b_Rturnoff(Read_I_b_rung_top());
    
    /* ] finish series */
}
