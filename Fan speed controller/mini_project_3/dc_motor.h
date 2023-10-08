/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: dc_motor.h
 *
 * Description: Source file for the AVR dc_motor driver
 *
 * Author: Mahmoud Tarek
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* DC_MOTOR HW Ports and Pins Ids */
#define DC_MOTOR_1_PORT_ID             PORTB_ID
#define DC_MOTOR_1_PIN_ID              PIN0_ID

#define DC_MOTOR_2_PORT_ID             PORTB_ID
#define DC_MOTOR_2_PIN_ID              PIN1_ID

#define NOT_ROTATING  0
#define ROTATING_CW   1
#define ROTATING_A_CW 2

typedef enum{
	STOP,CW,A_CW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Initialize the DcMotor:
 * 1. Setup the DcMotor pins directions by use the GPIO driver.
 * 2. Stop the DC-Motor at the beginning through the GPIO driver
 */
void DcMotor_Init(void);
/*
 * Description :
 * 1. The function responsible for rotate the DC Motor CW/ or A-CW or
 * stop the motor based on the state input state value.
 * 2. Send the required duty cycle to the PWM driver based on the
 * required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
