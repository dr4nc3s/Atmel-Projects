#ifndef _UTILITIES_
#define _UTILITIES_

#define uns8	uint8_t
#define uns16	uint16_t
#define uns32	uint32_t

#define		INPUT			0x00
#define		OUTPUT			0x01
#define		INPUT_PULLUP	0x02

#define PORTA		(PORT->Group[0])
#define PORTB		(PORT->Group[1])

void configPin(PortGroup port, uns32 pin, uns8 mode);

#endif