#include "sam_utils.h"

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