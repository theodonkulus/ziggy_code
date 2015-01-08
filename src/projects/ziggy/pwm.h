// pwm.h
// Jan 3 2014
// Theo Themistokleous
//Low level setup and movement control via PWM for ARM freedom board
//Channels are setup to be controlled individually
//If you want to reuse this module for other ports, you must modify Configure_TPM0()
//This header contains defines for servo mins and max based on 1us ticks

#ifndef _PWM_H_
#define _PWM_H_

#include "common.h"

//values in terms of uSec
#define SERVO_PERIOD 20000  //20ms in terms of 1us ticks 
#define SERVO_MAX 2400
#define SERVO_MIN 500

uint16 pulse_width_in_ticks(uint16 period, uint16 duty_cycle);
void Configure_TPM0(const uint16 period, const uint16 Ch1, const uint16 Ch2, 
	                                       const uint16 Ch3, const uint16 Ch4);

uint16 degrees_to_ticks(uint16 degrees);
void ch1_move(uint16 degrees); //bound from 0 to 180 degrees
void ch2_move(uint16 degrees);
void ch3_move(uint16 degrees);
void ch4_move(uint16 degrees);


#endif
