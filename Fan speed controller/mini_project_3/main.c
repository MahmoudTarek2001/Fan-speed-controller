#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
#include "adc.h"

int main(){

	uint8 temp;
	ADC_ConfigType ADC_Config;
	ADC_ConfigType * Config_Ptr = &ADC_Config ;
	Config_Ptr->prescaler = F_CPU_8;
	Config_Ptr->ref_volt = INTERNAL;
	LCD_init();
	DcMotor_Init();
	ADC_init(Config_Ptr);
	temp = LM35_getTemperature();
	LCD_displayStringRowColumn(0,0,"Fan is OFF");
	LCD_displayStringRowColumn(1,0,"Temp =    C");
	LCD_moveCursor(1, 7);
	LCD_intgerToString(temp);

	while(1){
		temp = LM35_getTemperature();

		if(temp<30){
			DcMotor_Rotate(STOP, 0);
			LCD_displayStringRowColumn(0,0,"Fan is OFF");
			LCD_moveCursor(1, 7);
			if(temp >= 10)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				/* In case the digital value is two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
			}
		}
		else if((temp>=30)&&(temp<60)){
			DcMotor_Rotate(CW, 25);
			LCD_displayStringRowColumn(0,0,"Fan is ON ");
			LCD_moveCursor(1, 7);
			LCD_intgerToString(temp);
		}
		else if((temp>=60)&&(temp<90)){
			DcMotor_Rotate(CW, 50);
			LCD_moveCursor(1, 7);
			LCD_intgerToString(temp);
		}
		else if((temp>=90)&&(temp<120)){
			DcMotor_Rotate(CW, 75);
			LCD_moveCursor(1, 7);
			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				/* In case the digital value is two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
			}
		}
		else{
			DcMotor_Rotate(CW, 100);
			LCD_moveCursor(1, 7);
			LCD_intgerToString(temp);
		}
	}
}
