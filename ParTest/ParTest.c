/*
	FreeRTOS V4.0.0 - Copyright (C) 2003-2006 Richard Barry.

	This file is part of the FreeRTOS distribution.

	FreeRTOS is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	FreeRTOS is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with FreeRTOS; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

	A special exception to the GPL can be applied should you wish to distribute
	a combined work that includes FreeRTOS, without being obliged to provide
	the source code for any proprietary components.  See the licensing section 
	of http://www.FreeRTOS.org for full details of how and when the exception
	can be applied.

	***************************************************************************
	See http://www.FreeRTOS.org for documentation, latest information, license 
	and contact details.  Please ensure to read the configuration and relevant 
	port sections of the online documentation.
	***************************************************************************
*/

/*
	Changes from V2.5.2
		
	+ All LED's are turned off to start.
*/

/* adapted to MCB2130 by mthomas */

#include "FreeRTOS.h"
#include "partest.h"

#if 0
// mthomas
#define partstFIRST_IO			( ( unsigned portLONG ) 0x400 )
#define partstNUM_LEDS			( 4 )
#define partstALL_OUTPUTS_OFF	( ( unsigned portLONG ) 0xffffffff )
#else
#define partstFIRST_IO			( ( unsigned portLONG ) 0x01000000 )
#define partstNUM_LEDS			( 8 )
#endif

/*-----------------------------------------------------------
 * Simple parallel port IO routines.
 *-----------------------------------------------------------*/
#if 0
void vParTestInitialise( void )
{
	/* This is performed from main() as the io bits are shared with other setup
	functions. */

	/* Turn all outputs off. */
	GPIO_IOSET = partstALL_OUTPUTS_OFF;
}
#else
void vParTestInitialise( void )
{
	/* This is performed from main() as the io bits are shared with other setup
	functions. */
	
	/* LED-Pins as outputs */
	IODIR1 = 0xFFFF0000;

	/* Turn all outputs off. */
	IOCLR1 = 0xFFFF0000;
}
#endif
/*-----------------------------------------------------------*/

#if 0
void vParTestSetLED( unsigned portBASE_TYPE uxLED, signed portBASE_TYPE xValue )
{
unsigned portLONG ulLED = partstFIRST_IO;

	if( uxLED < partstNUM_LEDS )
	{
		/* Rotate to the wanted bit of port 0.  Only P10 to P13 have an LED
		attached. */
		ulLED <<= ( unsigned portLONG ) uxLED;

		/* Set of clear the output. */
		if( xValue )
		{
			GPIO_IOCLR = ulLED;
		}
		else
		{
			GPIO_IOSET = ulLED;			
		}
	}	
}
#else
void vParTestSetLED( unsigned portBASE_TYPE uxLED, signed portBASE_TYPE xValue )
{
unsigned portLONG ulLED = partstFIRST_IO;

	if( uxLED < partstNUM_LEDS )
	{
		/* Rotate to the wanted bit of port 0.  Only P10 to P13 have an LED
		attached. */
		ulLED <<= ( unsigned portLONG ) uxLED;

		/* Set of set the output. */
		if( xValue )
		{
			IOSET1 = ulLED;
		}
		else
		{
			IOCLR1 = ulLED;			
		}
	}	
}
#endif
/*-----------------------------------------------------------*/

void vParTestToggleLED( unsigned portBASE_TYPE uxLED )
{
unsigned portLONG ulLED = partstFIRST_IO, ulCurrentState;

	if( uxLED < partstNUM_LEDS )
	{
		/* Rotate to the wanted bit of port 0.  Only P10 to P13 have an LED
		attached. */
		ulLED <<= ( unsigned portLONG ) uxLED;

		/* If this bit is already set, clear it, and visa versa. */
		ulCurrentState = IOPIN1;
		if( ulCurrentState & ulLED )
		{
			IOCLR1 = ulLED;
		}
		else
		{
			IOSET1 = ulLED;			
		}
	}	
}

