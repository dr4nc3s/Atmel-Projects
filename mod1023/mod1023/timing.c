#include "timing.h"

void timer32_enable() {
	_millis = 0;
	_micros = 0;
	TC0->COUNT32.CTRLA.bit.ENABLE = 1;
	
}

void timer32_disable() {
	TC0->COUNT32.CTRLA.bit.ENABLE = 0;
}

void timer32_init(uint32_t clkf) {
	_period_micros = clkf / MHZ_1;

	MCLK->APBCMASK.reg |= MCLK_APBCMASK_TC0;
	
	//32-bit, prescale sync, div4 prescaler
	TC0->COUNT32.CTRLA.reg |= (
		TC_CTRLA_MODE(TC_CTRLA_MODE_COUNT32_Val) |
		TC_CTRLA_PRESCSYNC(TC_CTRLA_PRESCSYNC_PRESC_Val) |
		TC_CTRLA_PRESCALER(TC_CTRLA_PRESCALER_DIV4_Val) 
	);
		
	TC0->COUNT32.CTRLBCLR.reg |= (
		TC_CTRLBCLR_DIR |
		TC_CTRLBCLR_LUPD |
		TC_CTRLBCLR_ONESHOT
	);
	
	TC0->COUNT32.EVCTRL.reg |= (
		TC_EVCTRL_MCEO0 |
		TC_EVCTRL_EVACT_RETRIGGER 		
	);
	
	TC0->COUNT32.INTENSET.reg |= TC_INTENSET_MC0;
	
	//Start counter at 0
	TC0->COUNT32.COUNT.reg = 0;
	TC0->COUNT32.CC[0].reg = _period_micros;
	
	// Configure interrupt request
	NVIC_DisableIRQ(TC0_IRQn);
	NVIC_ClearPendingIRQ(TC0_IRQn);
	NVIC_SetPriority(TC0_IRQn, 0);
	NVIC_EnableIRQ(TC0_IRQn);

	// Enable the TC5 interrupt request
	TC0->COUNT32.INTENSET.bit.MC0 = 1;
}


void TC0_Handler() {
	_micros++;
	if (_micros == 1000)
		_millis++;
		
	TC0->COUNT32.INTFLAG.bit.MC0 = 1;
}


uint32_t millis() {
	return _millis;
}
uint32_t micros() {
	return _micros;
}

