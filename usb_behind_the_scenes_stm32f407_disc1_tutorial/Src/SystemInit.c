/*
 * SystemInit.c
 *
 *  Created on: Sep 23, 2024
 *      Author: vdev
 */
#include "stdint.h"
#include "system_stm32f4xx.h"
#include "stm32f4xx.h"
#include "Helpers/logger.h"

LogLevel system_log_level = LOG_LEVEL_DEBUG;
uint32_t SystemCoreClock = 168000000; //168 MHz

// clock pre-scalar values obtained from STMCUBEIDE
// M-8, N-336, P-2, Q-7
// MCO1 - pre-scalar = 4
// AHB-1, APB1-4, APB2-2
static void configure_clock(void)
{

	MODIFY_REG(FLASH->ACR,
			FLASH_ACR_LATENCY,
			_VAL2FLD(FLASH_ACR_LATENCY, FLASH_ACR_LATENCY_5WS) //(FLASH_ACR_LATENCY_5WS << FLASH_ACR_LATENCY_Pos)
			);

	//ENABLE HSERCC_PLLCFGR_PLLM
	SET_BIT(RCC->CR, RCC_CR_HSEON);

	// wait until HSE is stable
	while(!READ_BIT(RCC->CR, RCC_CR_HSERDY));

	MODIFY_REG(RCC->PLLCFGR,
			RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLQ | RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLP,
			_VAL2FLD(RCC_PLLCFGR_PLLM, 8) | _VAL2FLD(RCC_PLLCFGR_PLLN, 336) | _VAL2FLD(RCC_PLLCFGR_PLLQ, 7) | _VAL2FLD(RCC_PLLCFGR_PLLSRC, 1)
			);

	//ENABLE PLL module
	SET_BIT(RCC->CR, RCC_CR_PLLON);

	// wait until PLL is stable
	while(!READ_BIT(RCC->CR, RCC_CR_PLLRDY));

	//switches system clock to PLL
	MODIFY_REG(RCC->CFGR,
			RCC_CFGR_SW,
			_VAL2FLD(RCC_CFGR_SW, RCC_CFGR_SW_PLL)
			);

	//Configures PPRE1 i.e APB1 pre-scalar
	MODIFY_REG(RCC->CFGR,
			RCC_CFGR_PPRE1,
			_VAL2FLD(RCC_CFGR_PPRE1, 16) // pre-scalar value of 4
			);

	//Configures PPRE2 i.e APB2 pre-scalar
	MODIFY_REG(RCC->CFGR,
			RCC_CFGR_PPRE2,
			_VAL2FLD(RCC_CFGR_PPRE2, 4) // pre-scalar value of 2 RCC_HCLK_DIV4
			);

	// wait until PLL is used
	while(READ_BIT(RCC->CFGR, RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

	//Disable HSI
	CLEAR_BIT(RCC->CR, RCC_CR_HSION);
}

void configure_mco1()
{
	//Configures PPRE1 i.e APB1 pre-scalar
	MODIFY_REG(RCC->CFGR,
			RCC_CFGR_MCO1 | RCC_CFGR_MCO1PRE,
			_VAL2FLD(RCC_CFGR_MCO1, 3) | _VAL2FLD(RCC_CFGR_MCO1PRE, 16) // selecting PLL as clock source and setting pre-scalar value of 4
			);

	//ENABLES PORTA Clock
	SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);

	//Configure PA8 OUTPUT SPEED
	MODIFY_REG(GPIOA->OSPEEDR,
			GPIO_OSPEEDR_OSPEED8,
			_VAL2FLD(GPIO_OSPEEDR_OSPEED8, 1) // selecting output speed to medium speed (1)
			);
	//Configure PA8 MODE
	MODIFY_REG(GPIOA->MODER,
			GPIO_MODER_MODE8,
			_VAL2FLD(GPIO_MODER_MODE8, 2) // selecting output speed to medium speed(1)
			);

}

void SystemInit(void)
{
	configure_mco1();
	configure_clock();
}
