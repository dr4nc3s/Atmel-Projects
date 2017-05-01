#ifndef _UTILITIES_
#define _UTILITIES_

#define uns8	uint8_t
#define uns16	uint16_t
#define uns32	uint32_t

#define		INPUT			(uint8_t)0x00
#define		OUTPUT			(uint8_t)0x01
#define		INPUT_PULLUP	(uint8_t)0x02

#define PORTA		(PORT->Group[0])
#define PORTB		(PORT->Group[1])

#define BIT_SET(word, pos)		((word) |= (1 << pos))
#define BIT_CLEAR(word, pos)	((word) &= (~(1 << pos)))

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

void pinConfig(PortGroup port, uns32 pin, uns8 mode);
void pinClear(PortGroup port, uns32 pin);

#endif