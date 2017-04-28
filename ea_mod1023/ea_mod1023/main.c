/*
 * ea_mod1023.c
 *
 * Created: 4/28/2017 3:52:57 PM
 * Author : Mobile Me
 */ 


#include "sam.h"
#include "sam_utils.h"


int main(void)
{
    /* Initialize the SAM system */
    SystemInit();

    /* Replace with your application code */
	//PORT->Group[0].DIR.reg = (1 << 15);
	//PORT->Group[0].OUT.reg &= ~(1 << 15);	//Drive PA00 high
	MAKE_OUTPUT(PORTA, 15);
	CLEAR_PIN(PORTA, 15);
	
	//MAKE_OUTPUT(PA15);
	//CLEAR_PIN(PA15);
	
    while (1) 
    {
		
    }
}

void init_i2c() {
	
}
