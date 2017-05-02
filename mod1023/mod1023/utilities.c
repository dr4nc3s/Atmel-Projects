/*
 * utilities.c
 *
 * Created: 4/29/2017 1:45:41 PM
 * Author : Mobile Me
 */ 

#include "sam.h"
#include "utilities.h"

void pinConfig(PortGroup *port, uns32 pin, uns8 mode) {
	switch(mode) {
		case INPUT:
			port->DIR.reg &= (~(1 << pin));
			break;
		case OUTPUT:
			//MAKE_OUTPUT(port, pin);
			port->DIR.reg |= (1 << pin);
			break;
		case INPUT_PULLUP:
			BIT_CLEAR(port->DIR.reg, pin);
			BIT_SET(port->PINCFG[pin].reg, port->PINCFG->bit.PULLEN);
			break;
		default:
			break;
	}
}

void pinClear(PortGroup *port, uns32 pin) {
	port->OUTCLR.reg |= (1 << pin);
}

void pinSet(PortGroup *port, uns32 pin) {
	port->OUTCLR.reg &= (~(1 << pin));
}

void pinToggle(PortGroup *port, uns32 pin) {
	port->OUTTGL.reg |= (1 << pin);
}