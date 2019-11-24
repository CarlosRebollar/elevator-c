//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*!
	\file	FloorManager.c
	\author	Carlos Palacios Jose Carrillo
	\date	October 16th, 2019
	\brief	File for managing logic of how the eelevato floors will work.
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

	#include "FloorManager.h"
	#include "ADC_Driver.h"

//------------------------------------------------------------------------------
// Defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Enums
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Variables
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------

/*!
    \fn		void FloorManager_SubSysInit (void)
    \return	This function does not return a value.
    \brief	Start ADC subsystem.
*/

	void FloorManager_SubSysInit(void) {
		ADC_vfnDriverInit();
	}

/*!
    \fn		uint_8 FloorManager_GetFloor (uint_8 bChannel, uint_8 *bpFloor)
    \return	This function does not return a value.
    \brief	Get value that ADC is reading (The floor in which you currently are.
*/

	uint_8 FloorManager_GetStop(uint_8 bChannel) {
		return ADC_bfnReadADC(bChannel);
	}

	uint_8 FloorManager_GetFloor(void) {
			for (uint_8 i = 0; i <= 2; i++) {
				if (ADC_bfnReadADC(i)) {
					return 1;
				}
			}

			return 0;
	}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
