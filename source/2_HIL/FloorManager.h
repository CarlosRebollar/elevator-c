//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*!
	\file	FloorManager.h
	\author	Carlos Palacios Jose Carrillo
	\date	October 16th, 2019
	\brief 	File for managment of elevator floors with the ADC.
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#ifndef _2_HIL_FLOORMANAGER_H_
#define _2_HIL_FLOORMANAGER_H_

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------

	#include "projectTypes.h"

//--------------------------------------------------------------------------
// Defines
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Enums
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Variables
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Functions
//--------------------------------------------------------------------------

	void FloorManager_SubSysInit(void);

	uint_8 FloorManager_GetStop(uint_8 channel);

	uint_8 FloorManager_GetFloor(void);

//------------------------------------------------------------------------------

#endif /* 2_HIL_FLOORMANAGER_H_ */
