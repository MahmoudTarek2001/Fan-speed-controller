/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for the AVR dc_motor driver
 *
 * Author: Mahmoud Tarek
 *
 *******************************************************************************/

#include "common_macros.h" /* For GET_BIT Macro */
#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description :
 * Initialize the DcMotor:
 * 1. Setup the DcMotor pins directions by use the GPIO driver.
 * 2. Stop the DC-Motor at the beginning through the GPIO driver
 */
void DcMotor_Init(void){
	/* Configure the direction for dc-motor pins as output pins */
	GPIO_setupPinDirection(DC_MOTOR_1_PORT_ID, DC_MOTOR_1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_2_PORT_ID, DC_MOTOR_2_PIN_ID, PIN_OUTPUT);
	/* Configure the initial output for dc-motor pins as Logic low */
	GPIO_writePin(DC_MOTOR_1_PORT_ID, DC_MOTOR_1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_2_PORT_ID, DC_MOTOR_2_PIN_ID, LOGIC_LOW);
}
/*
 * Description :
 * 1. The function responsible for rotate the DC Motor CW/ or A-CW or
 * stop the motor based on the state input state value.
 * 2. Send the required duty cycle to the PWM driver based on the
 * required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed){

	PWM_Timer0_Start(speed);/*generate pwm to make motor rotate at certain speed*/

	if(state == NOT_ROTATING){
		GPIO_writePin(DC_MOTOR_1_PORT_ID, DC_MOTOR_1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_2_PORT_ID, DC_MOTOR_2_PIN_ID, LOGIC_LOW);
	}
	else if(state == ROTATING_CW){
		GPIO_writePin(DC_MOTOR_1_PORT_ID, DC_MOTOR_1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_2_PORT_ID, DC_MOTOR_2_PIN_ID, LOGIC_HIGH);
	}
	else{
		GPIO_writePin(DC_MOTOR_1_PORT_ID, DC_MOTOR_1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_2_PORT_ID, DC_MOTOR_2_PIN_ID, LOGIC_HIGH);
	}
}
