//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*!
	\file	UART_Driver.c
	\author	Carlos Palacios and Jose Carrillo
	\date	October 24th, 2019
	\brief	File for configuration of UART;
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include "MKL25Z4.h"
#include "UART_Driver.h"

//------------------------------------------------------------------------------
// Defines
//------------------------------------------------------------------------------

/*!
    \def	UART CLOCK SRC
    \brief	Use to set clock source for the uart
*/

	#define UART0_CLOCK_SRC 1

/*!
    \def	PORTD_7
    \brief	TX pin for UART0
*/

	#define PORTD_7 7

/*!
    \def	PORTD_6
    \brief	Rx pin for UART0
*/

	#define PORTD_6 6

/*!
    \def	UART0_MUX_CONF
    \brief	Mux configuration for PORT E pins for UART0
*/

	#define UART0_MUX_CONF 3

/*!
    \def	SBR
    \brief	Value calculated for the baud rate module divisor
*/

	#define SBR 137

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
    \fn		void UART_vfnDriverInit (void)
    \return	This function does not return a value.
    \brief	Function for UART initial configuration.
*/

void UART_vfnDriverInit (void) {

	SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;

	SIM->SOPT2 |= SIM_SOPT2_UART0SRC(UART0_CLOCK_SRC);

	PORTD->PCR[PORTD_6] |= PORT_PCR_MUX(UART0_MUX_CONF);
	PORTD->PCR[PORTD_7] |= PORT_PCR_MUX(UART0_MUX_CONF);

	UART0->BDL = SBR & 0xFF;
	UART0->BDH = ((SBR >> 8) & 0x1F);
	UART0->BDH |= 1 << UART0_BDH_SBNS_SHIFT;

	UART0->C1 |= UART0_C1_PE(0);

	UART0->C2 |= UART0_C2_TE_MASK;
	UART0->C2 |= UART0_C2_RE_MASK;

	UART0->S1 = (1 << UART0_S1_IDLE_SHIFT);

}

/*!
    \fn		void UART_vfnDriverReceiveData (uint_8 *data)
    \return	This function does not return a value.
    \brief	Store data recevied from communication in pointer for later use.
*/

	void UART_vfnDriverReceiveData (uint_8 *data) {
		*data = UART0->D;
	}

/*!
	\fn		uint_8 UART_bfnDriverGetReadFlag (void)
	\return	Returns if UART has received data and is readable.
	\brief	Function for getting communication data.
*/

	uint_8 UART_bfnDriverGetReadFlag (void) {
		return UART0->S1 & UART0_S1_RDRF_MASK;
	}


//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
