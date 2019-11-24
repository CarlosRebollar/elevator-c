//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*!
	\file	Communication.c
	\author	Carlos Palacios Jose Carrillo
	\date	October 16th, 2019
	\brief	File for managing logic of how the eelevato floors will work.
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

	#include "Comunication.h"
	#include "UART_Driver.h"

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
    \fn		void Com_SubSysInit (void)
    \return	This function does not return a value.
    \brief	Start UART subsystem.
*/

	void Com_SubSysInit (void) {
		UART_vfnDriverInit();
	}

/*!
	\fn		void Com_ReceiveData (uint_8 *data)
	\return	This function does not return a value.
	\brief	Receive data from communication and store in in pointer.
*/

	void Com_ReceiveData (uint_8 *data) {
		UART_vfnDriverReceiveData (data);
	}

/*!
	\fn		uint_8 Com_getReadFlag (void)
	\return	UART read flag.
	\brief	Returns flag if the UART has read the data.
*/

	uint_8 Com_getReadFlag (void) {
		return UART_bfnDriverGetReadFlag();
	}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
