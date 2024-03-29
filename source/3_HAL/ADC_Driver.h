//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*!
	\file	ADC_Driver.h
	\author	Carlos Palacios Jose Carrillo
	\date	October 16th, 2019
	\brief 	File for function prototypes, macros, and enums for ADC_driver.c
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#ifndef _3_HAL_ADC_DRIVER_H_
#define _3_HAL_ADC_DRIVER_H_

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

	void ADC_vfnDriverInit (void);

	uint_8 ADC_bfnReadADC (uint_8 bChannel);

//------------------------------------------------------------------------------


#endif /* 3_HAL_ADC_DRIVER_H_ */
