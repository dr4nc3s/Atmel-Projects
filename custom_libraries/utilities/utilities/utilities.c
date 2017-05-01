/*
 * utilities.c
 *
 * Created: 4/29/2017 1:45:41 PM
 * Author : Mobile Me
 */ 

#include "sam.h"
#include "utilities.h"

#define BIT_SET(word, pos)		((word) |= (1 << pos))
#define BIT_CLEAR(word, pos)	((word) &= (~(1 << pos)))

/*	Pin Control Macros	*/


#define MAKE_INPUT(port, pin) 	(((port).DIR.reg) &= (~(1 << pin)))
#define MAKE_OUTPUT(port, pin)	(((port).DIR.reg) |= ((1 << pin)))

#define SET_PIN(port, pin)		(((port).OUT.reg) |= ((1 << pin)))
#define CLEAR_PIN(port, pin)	(((port).OUT.reg) &= (~(1 << pin)))

#define READ_PIN(port, pin)		(((port).IN.reg) >> pin)	//Come back later to constrain size
//Output pin is toggled. Input pin pull-direction toggled
#define TOGGLE_PIN(port, pin)	(((port).OUTTGL.reg) |= (1 << pin>))

//PORT->Group[1].PINCFG[1].bit.PULLEN
#define ENABLE_PULLUP(port, pin)		((port).PINCFG[(pin)].reg |= (1 << 2))
#define DISABLE_PULLUP(port, pin)		((port).PINCFG[(pin)].reg &= (~(1 << 2)))


void configPin(PortGroup port, uns32 pin, uns8 mode) {
	switch(mode) {
		case INPUT:
			BIT_CLEAR(port.DIR.reg, pin);
			break;
		case OUTPUT:
			BIT_SET(port.DIR.reg, pin);
			break;
		case INPUT_PULLUP:
			BIT_CLEAR(port.DIR.reg, pin);
			BIT_SET(port.PINCFG[pin].reg, port.PINCFG->bit.PULLEN);
			break;
		default:
			break;
	}
}
