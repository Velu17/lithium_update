
#include "main.h"
#include "adc.h"
#include <xc.h>
#define R1 50000;
#define R2 100000;

static void init_config(void)
{
	LED1 = OFF;

	TRISB0 = 0;

    init_adc();
}

void main(void)
{
    unsigned short adc_reg_val;

    init_config();

    while (1)
    {
        adc_reg_val = read_adc(CHANNEL4);
        int adcValue=analogRead(VOLTAGE_PIN);
        long voltage =(adcValue/1023.0)*5.0;
        long inputVoltage= voltage * ((R1+R2)/R2);
        serial.print("Voltage: ");
        serial.print(inputvoltage);
        serial.print(" V");
        glow_led(adc_reg_val);
    }
}













