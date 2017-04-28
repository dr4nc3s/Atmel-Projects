#ifndef __sam_utils_h
#define __sam_utils_h

#define uns8	uint8_t
#define uns16	uint16_t
#define uns32	uint32_t

/*	Pin Control Macros	*/
#define PORTA		(PORT->Group[0])
#define PORTB		(PORT->Group[1])

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


#endif