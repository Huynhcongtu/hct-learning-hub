#ifndef QNU_COMMON_H
#define QNU_COMMON_H
typedef unsigned char u8;
#ifdef HOST_CHECK
#include <stdint.h>
typedef uint16_t u16;
/* HOST_CHECK checks syntax, not 8051 peripheral behaviour. */
#define PIN(n,p,b) static volatile u8 n
#define ISR(n)
#define ROM const
#define NOP() ((void)0)
static volatile u8 P0,P1,P2,P3,TMOD,TCON,TH0,TL0,TH1,TL1;
static volatile u8 TR0,TR1,TF0,TF1,EA,ET0,ES,EX0,IT0,IE0;
static volatile u8 RI,TI,SCON,SBUF,PCON;
#else
typedef unsigned int u16; /* Keil C51: 16 bit */
#include <REG52.H>
#include <intrins.h>
#define PIN(n,p,b) sbit n = p^b
#define ISR(n) interrupt n
#define ROM code
#define NOP() _nop_()
#endif
#endif
