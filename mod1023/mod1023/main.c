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
#define PB15	PORTB, 15

uns32 current, previous, elapsed;

static inline uns8 gclk1_syncing() {
	if (GCLK->SYNCBUSY.bit.GENCTRL1 & GCLK_SYNCBUSY_GENCTRL1) 
		return 1;
	else
		return 0;
}

/*
	Test by delivering output to IOpin PB15
*/
static void _initGclkSource() {
	uns32 gclk_ctrl_reg = (0x0002 << 16) | 
		GCLK_GENCTRL_SRC_OSC48M |
		GCLK_GENCTRL_OE |
		GCLK_GENCTRL_OOV;
		GCLK_GENCTRL_DIVSEL |
		GCLK_GENCTRL_GENEN;
	
	GCLK->GENCTRL[1].reg |= gclk_ctrl_reg;	 
	while (gclk1_syncing()) {};
	GCLK->GENCTRL[1].reg |= (0x0001 << 8);
}

int main(void)
{
    /* Initialize the SAM system */
    SystemInit();

	pinConfig(PA15, 0x01);
	
	pinConfig(PB15, OUTPUT);
	pinSet(PB15);
	pinClear(PB15);
	pinFunction(PB15, IO_PERIPH_H);
	
	_initGclkSource();
	
	pinClear(PA15);
    while (1) 
    {
		//current = millis();
		//if (current - previous >= 1000) {
			//pinToggle(PA15);
			//previous = millis();
		//}
    }
}




