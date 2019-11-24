//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*!
	\file	EngineManager.c
	\author	Carlos Palacios Jose Carrillo
	\date	October 16th, 2019
	\brief	File for managing managment of engine movement.
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

	#include "EngineManager.h"
	#include "GPIO_Driver.h"

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
    \brief	Start Engine subsystem.
*/

	void EngineManager_SubSysInit(void) {
		GPIO_vfnDriverInit();
	}

/*!
	\fn		void EngineManager_MoveEngine (void)
	\return	This function does not return a value.
	\brief	Moves the engine to the desire position.
*/

	void EngineManager_MoveEngine(uint_8 initialPos, uint_8 desiredPos) {
		switch(initialPos) {
			case 0:
				GPIO_vfnMoveEngineRight();
				break;
			case 1:
				switch(desiredPos) {
					case 0:
						GPIO_vfnMoveEngineLeft();
						break;
					case 2:
						GPIO_vfnMoveEngineRight();
						break;
				}
				break;
			case 2:
				GPIO_vfnMoveEngineLeft();
				break;
		}
	}

/*!
	\fn		void FloorManager_SubSysInit (void)
	\return	This function does not return a value.
	\brief	Enable engine
*/

	void EngineManager_EnableEngine(void) {
		GPIO_vfnEnableEngine();
	}

/*!
	\fn		void FloorManager_SubSysInit (void)
	\return	This function does not return a value.
	\brief	Disable engine.
*/

	void EngineManager_DisableEngine(void) {
		GPIO_vfnDisableEngine();
	}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
