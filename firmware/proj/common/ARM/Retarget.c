#include "in_config.h"

/*----------------------------------------------------------------------------
 * Name:    Retarget.c
 * Purpose: 'Retarget' layer for target-dependent low level functions
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2012 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <time.h>

#include ".\hal\hal_uart.h"

#pragma import(__use_no_semihosting_swi)

extern int SER_PutChar(int c);
extern int SER_GetChar(char *p);
static long timeval;

struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;
FILE __stdin;
FILE __stderr;

int fputc(int c, FILE *f) {
#if CFG_DBG_EN
#if CFG_DBG_IF_UART
	//return 1;
  if (c == '\n')  {
    SER_PutChar('\r');
  }
  return (SER_PutChar(c));
#else
	return 1;
#endif
#else
	return 1;
#endif
}

int fgetc(FILE *f) {
#if CFG_DBG_IF_UART
	char ch;
	SER_GetChar(&ch);
	SER_PutChar(ch);
	if (ch == 0x0d){
		SER_PutChar(0x0a);
		return EOF;
	}else
		return ch;
#else
	return 0;
#endif
}

int ferror(FILE *f) {
  /* Your implementation of ferror */
  return EOF;
}

void _ttywrch(int c) {
#if CFG_DBG_EN
#if CFG_DBG_IF_UART
  SER_PutChar(c);
#endif
#endif
}

clock_t clock(void) 	/* Review */
{
  return timeval;
}

void _clock_init(void) 
{
  timeval = 0;
}


void _sys_exit(int return_code) {
label:  goto label;  /* endless loop */
}
