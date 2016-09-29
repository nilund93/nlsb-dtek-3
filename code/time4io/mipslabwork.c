/* mipslabwork.c

   This file written 2015 by F Lundevall

   This file should be changed by YOU! So add something here:

   This file modified 2015-12-24 by Ture Teknolog 

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int mytime = 0x5957;

char textstring[] = "text, more text, and even more text!";
//from lecture
#define TRISF  PIC32_R (0x86140)
#define TRISFCLR  PIC32_R (0x86144)
#define TRISFSET  PIC32_R (0x86148)
#define TRISFINv  PIC32_R (0x8614C)
#define PORTF PIC32_R (0x86150)
#define PIC32_R(a) * (volatile unsigned*)(0xBF800000 + (a))

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

/* Lab-specific initialization goes here */
void labinit( void )
{
  //From lecture slides
  //https://www.kth.se/social/files/57e95716f27654773d8ad6c5/lecture5-spp2.pdf
  TRISE &= ~0xff;
  TRISF |= 0x2;
  PORTE = (PORTF >>1) / 0x1;

  return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
  delay( 1000 );
  time2string( textstring, mytime );
  display_string( 3, textstring );
  display_update();
  tick( &mytime );
  display_image(96, icon);
}
