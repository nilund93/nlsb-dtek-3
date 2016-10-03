#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"

int getsw( void ){
	/*
		de 4 msb av returvärdet innehåller värdet från
		switcharna SW4, SW3, SW2, SW1.
		SW1 är den minst signifikanta biten.
		Alla andra bitar måste vara 0.
		Funktionen kan inte kallas om PORTD inte initierats rätt
		Switcharna är connectade genom bitarna 11 till 8
		i PORTD
		
	*/
		
}