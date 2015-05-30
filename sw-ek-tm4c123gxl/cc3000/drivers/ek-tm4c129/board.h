//*****************************************************************************
//
// board.h - Board definitions for CC3000 on EK-TM4C129
//
// Copyright (c) 2014 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.1.0.12573 of the Tiva Firmware Development Package.
//
//*****************************************************************************
#ifndef __BOARD_H__
#define __BOARD_H__

//*****************************************************************************
//
// Global holding the system clock rate in Hz.
//
//*****************************************************************************
extern uint32_t g_ui32SysClock;

//*****************************************************************************
//
// Defines for setting up the system tick counter.
//
//*****************************************************************************
#define SYSTICK_PER_SECOND                10

//*****************************************************************************
//
// SPI defines
//
//*****************************************************************************

//*****************************************************************************
//
// SPI General Defines
//
//*****************************************************************************
#define SPI_WINDOW_SIZE         DMA_WINDOW_SIZE
#define DMA_WINDOW_SIZE         1024

//*****************************************************************************

//
// The desired system clock rate.
//
//*****************************************************************************
#define SYSCLOCK_RATE_HZ        60000000

//*****************************************************************************
//
// The parameter to pass to SysCtlDelay() to cause a 50uS delay.
//
//*****************************************************************************
#define DELAY_50_MICROSECONDS   ((SYSCLOCK_RATE_HZ / 20000) / 3)

//*****************************************************************************
//
// Make sure one or other boosterpack header has been selected in the build
// environment.
//
//*****************************************************************************
#if (!(defined CC3000_USE_BOOSTERPACK1) && !(defined CC3000_USE_BOOSTERPACK2))
#error Please define one of CC3000_USE_BOOSTERPACK1 or CC3000_USE_BOOSTERPACK2
#endif

//*****************************************************************************
//
// CC3000 Board specific Macros
//
//*****************************************************************************
#define ASSERT_CS()          (MAP_GPIOPinWrite(SPI_CS_PORT, SPI_CS_PIN, 0))
#define DEASSERT_CS()        (MAP_GPIOPinWrite(SPI_CS_PORT, SPI_CS_PIN, SPI_CS_PIN))

#if defined(CC3000_USE_BOOSTERPACK2)
//*****************************************************************************
//
// SPI and IRQ pins used with the BoosterPack2 connector.
//
//*****************************************************************************

//
// IRQ settings - PM7
//
#define SYSCTL_PERIPH_IRQ_PORT      SYSCTL_PERIPH_GPIOM
#define SPI_GPIO_IRQ_BASE           GPIO_PORTM_BASE
#define SPI_IRQ_PIN                 GPIO_PIN_7
#define INT_GPIO_SPI                INT_GPIOM

//
// SW EN settings - PD2
//
#define SYSCTL_PERIPH_SW_EN_PORT    SYSCTL_PERIPH_GPIOD
#define SPI_GPIO_SW_EN_BASE         GPIO_PORTD_BASE
#define SPI_EN_PIN                  GPIO_PIN_2

//
// CS settings - PP5
//
#define SPI_CS_PORT                 GPIO_PORTP_BASE
#define SYSCTL_PERIPH_SPI_PORT      SYSCTL_PERIPH_GPIOP
#define SPI_CS_PIN                  GPIO_PIN_5

//
// SPI pins PQ0, PQ2, PQ3
//
#define SPI_BASE                    SSI3_BASE
#define SYSCTL_PERIPH_SPI           SYSCTL_PERIPH_SSI3
#define SYSCTL_PERIPH_SPI_BASE      SYSCTL_PERIPH_GPIOQ
#define SPI_PORT                    GPIO_PORTQ_BASE
#define SPI_CLK_PIN                 GPIO_PIN_0
#define SPI_CLK_MUX_SEL             GPIO_PQ0_SSI3CLK
#define SPI_RX_PIN                  GPIO_PIN_3
#define SPI_RX_MUX_SEL              GPIO_PQ3_SSI3XDAT1
#define SPI_TX_PIN                  GPIO_PIN_2
#define SPI_TX_MUX_SEL              GPIO_PQ2_SSI3XDAT0
#define SPI_UDMA_RX_CHANNEL         UDMA_CH14_SSI3RX
#define SPI_UDMA_TX_CHANNEL         UDMA_CH15_SSI3TX
#define INT_SPI                     INT_SSI3

#endif

#if defined(CC3000_USE_BOOSTERPACK1)
//*****************************************************************************
//
// SPI and IRQ pins used with the BoosterPack1 connector.
//
//*****************************************************************************

//
// IRQ settings - PM3
//
#define SYSCTL_PERIPH_IRQ_PORT      SYSCTL_PERIPH_GPIOM
#define SPI_GPIO_IRQ_BASE           GPIO_PORTM_BASE
#define SPI_IRQ_PIN                 GPIO_PIN_3
#define INT_GPIO_SPI                INT_GPIOM

//
// SW EN settings - PE4
//
#define SYSCTL_PERIPH_SW_EN_PORT    SYSCTL_PERIPH_GPIOE
#define SPI_GPIO_SW_EN_BASE         GPIO_PORTE_BASE
#define SPI_EN_PIN                  GPIO_PIN_4

//
// CS settings - PH2
//
#define SPI_CS_PORT                 GPIO_PORTH_BASE
#define SYSCTL_PERIPH_SPI_PORT      SYSCTL_PERIPH_GPIOH
#define SPI_CS_PIN                  GPIO_PIN_2

//
// SPI pins PD3, PD1, PD0
//
#define SPI_BASE                    SSI2_BASE
#define SYSCTL_PERIPH_SPI           SYSCTL_PERIPH_SSI2
#define SYSCTL_PERIPH_SPI_BASE      SYSCTL_PERIPH_GPIOD

#define SPI_PORT                    GPIO_PORTD_BASE
#define SPI_CLK_PIN                 GPIO_PIN_3
#define SPI_CLK_MUX_SEL             GPIO_PD3_SSI2CLK

#define SPI_RX_PIN                  GPIO_PIN_0
#define SPI_RX_MUX_SEL              GPIO_PD0_SSI2XDAT1

#define SPI_TX_PIN                  GPIO_PIN_1
#define SPI_TX_MUX_SEL              GPIO_PD1_SSI2XDAT0

#define SPI_UDMA_RX_CHANNEL         UDMA_CH12_SSI2RX
#define SPI_UDMA_TX_CHANNEL         UDMA_CH13_SSI2TX
#define INT_SPI                     INT_SSI2

#endif

//*****************************************************************************
//
// UART defines
//
//*****************************************************************************
#define CC3000_UART_BASE                UART0_BASE
#define CC3000_UART_SYSCTL_PERIPH_GPIO  SYSCTL_PERIPH_GPIOA
#define CC3000_UART_SYSCTL_PERIPH_UART  SYSCTL_PERIPH_UART0
#define CC3000_UART_GPIO_RX             GPIO_PA0_U0RX
#define CC3000_UART_GPIO_TX             GPIO_PA1_U0TX
#define CC3000_UART_GPIO_PORT_BASE      GPIO_PORTA_BASE
#define CC3000_UART_GPIO_PINS           (GPIO_PIN_0 | GPIO_PIN_1)
#define CC3000_UART_INT                 INT_UART0

//*****************************************************************************
//
// LED defines. These correspond to D1, D2, D3 and D4 on ek-tm4c129
//
//*****************************************************************************
#define CC3000_LED_1_SYSCTL_PERIPH      SYSCTL_PERIPH_GPION
#define CC3000_LED_1_PORT               GPIO_PORTN_BASE
#define CC3000_LED_1_PIN                GPIO_PIN_1

#define CC3000_LED_2_SYSCTL_PERIPH      SYSCTL_PERIPH_GPION
#define CC3000_LED_2_PORT               GPIO_PORTN_BASE
#define CC3000_LED_2_PIN                GPIO_PIN_0

#define CC3000_LED_3_SYSCTL_PERIPH      SYSCTL_PERIPH_GPIOF
#define CC3000_LED_3_PORT               GPIO_PORTF_BASE
#define CC3000_LED_3_PIN                GPIO_PIN_4

#define CC3000_LED_4_SYSCTL_PERIPH      SYSCTL_PERIPH_GPIOF
#define CC3000_LED_4_PORT               GPIO_PORTF_BASE
#define CC3000_LED_4_PIN                GPIO_PIN_0

typedef enum
{
    LED1,
    LED2,
    LED3,
    LED4
}
tBoardLED;

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
extern void pio_init(void);
extern void initLEDs(void);
extern long ReadWlanInterruptPin(void);
extern void WlanInterruptEnable(void);
extern void WlanInterruptDisable(void);
extern void WriteWlanPin( unsigned char val );
extern void InitSysTick(void);
extern void SysTickHandler(void);
extern void initClk(void);
extern void turnLedOn(tBoardLED eLED);
extern void turnLedOff(tBoardLED eLED);

#endif //__BOARD_H__
