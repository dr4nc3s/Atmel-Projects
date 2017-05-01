#ifndef __timing_h
#define __timing_h

#include "sam.h"

#define	MHZ_1	1000000UL

static uint32_t _millis;
static uint32_t _micros;
static uint32_t _period_micros;

void timer32_enable();

void timer32_disable();

void timer32_init(uint32_t clkf);

//Increment _micros and _millis
void timer32_irq();

uint32_t millis();

uint32_t micros();


#endif
