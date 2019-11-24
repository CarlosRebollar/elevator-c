#include "Comunication.h"
#include "EngineManager.h"
#include "FloorManager.h"
#include "MKL25Z4.h"

int main(void) {

	uint_8 initialFloor = 0;
	uint_8 ADC_Channel = 1;
	uint_8 stop = 0;

	Com_SubSysInit();
	EngineManager_SubSysInit();
	FloorManager_SubSysInit();

	while(1) {
		stop = FloorManager_GetStop(ADC_Channel);

		if (stop) {
			EngineManager_DisableEngine();
			initialFloor = ADC_Channel;
		} else {
			EngineManager_EnableEngine();
			EngineManager_MoveEngine(initialFloor, ADC_Channel);
		}
	}

  	return 0;
}
