//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*!
	\file	GPIO_Driver.c
	\author	Carlos Palacios Jose Carrillo
	\date	October 16th, 2019
	\brief	File for configuration GPIOS.
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include "MKL25Z4.h"
#include "GPIO_Driver.h"

//------------------------------------------------------------------------------
// Defines
//------------------------------------------------------------------------------

/*!
    \def	ENGINGE_PIN_1 Pin 1 for engine.
    \brief	Pin used for combination of the engine.
*/

	#define ENGINGE_PIN_1 4

/*!
    \def	ENGINGE_PIN_2 Pin 2 for engine.
    \brief	Pin used for combination of the engine.
*/

	#define ENGINGE_PIN_2 5

/*!
    \def	ENGINGE_PIN_ENABLE Pin for enable of the engine.
    \brief	Pin used for enabling the engine in 1 or 0.
*/

	#define ENGINGE_PIN_ENABLE 3

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
    \fn		void GIO_vfnDriverInit (void)
    \return	This function does not return a value.
    \brief	Function for initial GPIOs configurations
*/

	void GPIO_vfnDriverInit (void) {

		SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;

		PORTE->PCR [ENGINGE_PIN_1] |= ( 1 <<PORT_PCR_MUX_SHIFT);
		PORTE->PCR [ENGINGE_PIN_2] |= ( 1 <<PORT_PCR_MUX_SHIFT);
		PORTE->PCR [ENGINGE_PIN_ENABLE] |= ( 1 <<PORT_PCR_MUX_SHIFT);



		GPIOE->PDDR |= (1 << ENGINGE_PIN_1);
		GPIOE->PDDR |= (1 << ENGINGE_PIN_2);
		GPIOE->PDDR |= (1 << ENGINGE_PIN_ENABLE);
	}

/*!
	\fn		void GPIO_vfnMoveEngine (void)
	\return	This function does not return a value.
	\brief	Function for moving the engine with the GPIOs.
*/
	void GPIO_vfnMoveEngineRight (void) {
		GPIOE->PDOR &= ~(1 << ENGINGE_PIN_1);
		GPIOE->PDOR &= ~(1 << ENGINGE_PIN_2);

		GPIOE->PDOR |= (1<<ENGINGE_PIN_1);
		GPIOE->PDOR &= ~(1<<ENGINGE_PIN_2);
	}

/*!
	\fn		void GPIO_vfnMoveEngineLeft (void)
	\return	This function does not return a value.
	\brief	Function for moving the engine with the GPIOs.
*/
	void GPIO_vfnMoveEngineLeft (void) {
		GPIOE->PDOR &= ~(1 << ENGINGE_PIN_1);
		GPIOE->PDOR &= ~(1 << ENGINGE_PIN_2);

		GPIOE->PDOR &= ~(1<<ENGINGE_PIN_1);
		GPIOE->PDOR |= (1<<ENGINGE_PIN_2);
	}

/*!
	\fn		void GPIO_vfnEnableEngine (void)
	\return	This function does not return a value.
	\brief  Set engine enable to 1.
*/
	void GPIO_vfnEnableEngine (void) {
		GPIOE->PDOR |= (1 << ENGINGE_PIN_ENABLE);
	}

/*!
	\fn		void GPIO_vfnDisableEngine (void)
	\return	This function does not return a value.
	\brief	Set engine enable to 0.
*/
	void GPIO_vfnDisableEngine (void) {
		GPIOE->PDOR &= ~(1 << ENGINGE_PIN_ENABLE);
	}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
