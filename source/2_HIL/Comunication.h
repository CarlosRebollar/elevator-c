/*
 * Comunication.h
 *
 *  Created on: Oct 24, 2019
 *      Author: rebo
 */

#ifndef _2_HIL_COMUNICATION_H_
#define _2_HIL_COMUNICATION_H_

#include "projectTypes.h"

void Com_SubSysInit (void);

void Com_ReceiveData (uint_8 *data);

uint_8 Com_getReadFlag (void);

#endif /* 2_HIL_COMUNICATION_H_ */
