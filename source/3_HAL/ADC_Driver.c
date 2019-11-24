//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*!
	\file	ADC_Driver.c
	\author	Carlos Palacios
	\date	October 16th, 2019
	\brief	File for configuration of ADC and returning ADC value.
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include "MKL25Z4.h"
#include "ADC_Driver.h"

//------------------------------------------------------------------------------
// Defines
//------------------------------------------------------------------------------
/*!
    \def	PORTE_20 AS ADC
    \brief	Pin used for ADC input. Floor 0
*/

	#define PORTE_20 20

/*!
    \def	PORTE_21 AS ADC
    \brief	Pin used for ADC input. Floor 1
*/

	#define PORTE_21 21

/*!
    \def	PORTE_22 AS ADC
    \brief	Pin used for ADC input. Floor 2
*/

	#define PORTE_22 22

/*!
    \def	ADC CHANNEL SE0
    \brief	Pin used for ADC input. Floor 0.
*/

	#define ADC_CHANNEL_SE0  0

/*!
    \def	ADC CHANNEL SE3
    \brief	Pin used for ADC input. Floor 2.
*/

	#define ADC_CHANNEL_SE3  3

/*!
    \def	ADC CHANNEL SE4a
    \brief	Pin used for ADC input. Floor 1.
*/

	#define ADC_CHANNEL_SE4a 4

/*!
    \def	SIXTEEN_SAMPLES
    \brief	Value used to set ADC to use an average of 16 samples
*/

	#define SIXTEEN_SAMPLES 2


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
    \fn		void ADC_vfnDriverInit (void)
    \return	This function does not return a value.
    \brief	Function for ADC initial configuration.
*/

	void ADC_vfnDriverInit (void) {

		SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
		SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;

		PORTE->PCR[PORTE_20] &= ~PORT_PCR_MUX_MASK;
		PORTE->PCR[PORTE_21] &= ~PORT_PCR_MUX_MASK;
		PORTE->PCR[PORTE_22] &= ~PORT_PCR_MUX_MASK;

		ADC0->CFG1 &= ~ADC_CFG1_MODE_MASK;
		ADC0->CFG1 &= ~ADC_CFG1_ADLPC_MASK;

		ADC0->CFG2 &= ~ADC_CFG2_ADHSC_MASK;

		ADC0->SC2 &= ~ADC_SC2_ADTRG_MASK;
		ADC0->SC2 &= ~ADC_SC2_DMAEN_MASK;

		ADC0->SC3 |= ADC_SC3_AVGE_MASK;
		ADC0->SC3 |= ADC_SC3_AVGS(SIXTEEN_SAMPLES);
	}

/*!
    \fn		uint_8 ADC_bfnReadADC (uint_8 bChannel)
    \param	bChannel This parameter is for indicating which channel of the ADC you want to read.
    \return This function returns true if is between 0 and 50 the value gotten from the ADC.
    \brief	This function starts the coco on the desired channel for the ADC and get its value.
*/

	uint_8 ADC_bfnReadADC (uint_8 bChannel) {
		switch (bChannel) {
			case 0:
				ADC0->SC1[0] = ADC_CHANNEL_SE0;
				break;
			case 1:
				ADC0->SC1[0] = ADC_CHANNEL_SE4a;
				break;
			case 2:
				ADC0->SC1[0] = ADC_CHANNEL_SE3;
				break;
		}

		uint_8 i = 1;
		while(i) {
			if (ADC0->SC1[0] & ADC_SC1_COCO_MASK) {
				i = 0;
			}
		}

		uint_8 adcOutput = ADC0->R[0];

		if (adcOutput <= 50)
			return 1;

		return 0;
	}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
