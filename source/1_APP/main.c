#include "Comunication.h"
#include "EngineManager.h"
#include "FloorManager.h"

int main(void) {
	uint_8 ADC_Channel = 1;
	uint_8 stop = 0;

	Com_SubSysInit();
	EngineManager_SubSysInit();
	FloorManager_SubSysInit();


	EngineManager_EnableEngine();
	EngineManager_MoveEngine(0, 1);

	uint_8 initialFloor = FloorManager_GetFloor();


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
