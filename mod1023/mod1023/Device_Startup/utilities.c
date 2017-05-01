/*
 * utilities.c
 *
 * Created: 4/29/2017 1:45:41 PM
 * Author : Mobile Me
 */ 

#include "sam.h"
#include "utilities.h"




void pinMode(PortGroup port, uns32 pin, uns8 mode) {
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

void pinSet(PortGroup port, uns32 pin) {
	port.OUT.reg |= (1 << pin);
}

void pinClear(PortGroup port, uns32 pin) {
	port.OUT.reg &= (~(1 << pin));
}

void pinToggle(PortGroup port, uns32 pin) {
	port.OUTTGL.reg = (1 << pin);
}