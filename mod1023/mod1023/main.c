/*
 * mod1023.c
 *
 * Created: 5/1/2017 12:12:35 PM
 * Author : Mobile Me
 */ 


#include "sam.h"
#include "utilities.h"
#include "timing.h"

#define PA15	PORTA, 15

uns32 current, previous, elapsed;

int main(void)
{
    /* Initialize the SAM system */
    SystemInit();
	//timer32_init(SystemCoreClock);
	//timer32_enable();
	MAKE_OUTPUT(PORTA, 15);
	//pinConfig(PA15, 0x01);
	pinClear(PA15);
	//previous = millis();
    while (1) 
    {
		//current = millis();
		//if (current - previous >= 1000) {
		//	pinToggle(PA15);
		//	previous = millis();
		//}
    }
}


