#include "FloorManager.h"
#include "MKL25Z4.h"

#define LED_1 30
#define LED_2 29
#define LED_3 23

int main(void) {

	uint_8 ADC_Channel = 2;

	FloorManager_SubSysInit();

	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;

	PORTE->PCR[LED_1] |= (1 << PORT_PCR_MUX_SHIFT);
	PORTE->PCR[LED_2] |= (1 << PORT_PCR_MUX_SHIFT);
	PORTE->PCR[LED_3] |= (1 << PORT_PCR_MUX_SHIFT);

	// SET PINS FOR LEDS AS OUTPUT *PREGUNTAR
	GPIOE->PDDR |= (1 << LED_1);

	while(1) {
		uint_8 floor = FloorManager_GetStop(ADC_Channel);

		if (floor) {
			GPIOE->PDOR = (1 << LED_1);
		} else {
			GPIOE->PDOR = ~(1 << LED_1);
		}
	}

  	return 0;
}
