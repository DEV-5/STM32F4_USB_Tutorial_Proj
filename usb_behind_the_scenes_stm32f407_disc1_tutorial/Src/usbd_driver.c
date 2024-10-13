/*
 * usbd_driver.c
 *
 *  Created on: Sep 29, 2024
 *      Author: vdev
 */

#include "usbd_driver.h"

void initialize_usb_pins()
{
	//Enables the clock for GPIOA
	SET_BIt(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);

	//PA11(Dm) and PA12 (Dp)
	MODIFY_REG(GPIOA->AFR[1],
			GPIO_AFRH_AFSEL11 | GPIO_AFRH_AFSEL12,
			_VAL2FLD(GPIO_AFRH_AFSEL11, 0xc) | _VAL2FLD(GPIO_AFRH_AFSEL12, 0xc)
			);
	// Configures USB pins (in GPIOA) to work in alternate function mode
	MODIFY_REG(GPIOA->MODER,
			GPIO_MODE_MODER11 | GPIO_MODE_MODER12,
			_VAL2FLD(GPIO_MODER_MODE11, 2) | _VAL2FLD(GPIO_MODER_MODE12, 2)
			);
}
