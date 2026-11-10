#ifndef __IO_CONFIG_H__
#define __IO_CONFIG_H__

#include "stm32f4xx.h"
#include "compiler.h"
#include "daplink.h"

// Connected LED (синий светодиод на Black Pill - PC13)
#define CONNECTED_LED_PORT              GPIOC
#define CONNECTED_LED_PIN               GPIO_PIN_13
#define CONNECTED_LED_PIN_Bit           13

// Target Reset (nRESET -> PB15)
#define nRESET_PIN_PORT                 GPIOB
#define nRESET_PIN                      GPIO_PIN_15
#define nRESET_PIN_Bit                  15

// SWD CLK (SWCLK -> PB13)
#define SWCLK_TCK_PIN_PORT              GPIOB
#define SWCLK_TCK_PIN                   GPIO_PIN_13
#define SWCLK_TCK_PIN_Bit               13

// SWD IO (SWDIO -> PB14)
#define SWDIO_OUT_PIN_PORT              GPIOB
#define SWDIO_OUT_PIN                   GPIO_PIN_14
#define SWDIO_OUT_PIN_Bit               14

#define SWDIO_IN_PIN_PORT               GPIOB
#define SWDIO_IN_PIN                    GPIO_PIN_14
#define SWDIO_IN_PIN_Bit                14

// Остальные светодиоды заведены на PC13
#define RUNNING_LED_PORT                GPIOC
#define RUNNING_LED_PIN                 GPIO_PIN_13
#define RUNNING_LED_Bit                 13

#define PIN_HID_LED_PORT                GPIOC
#define PIN_HID_LED                     GPIO_PIN_13
#define PIN_HID_LED_Bit                 13

#define PIN_CDC_LED_PORT                GPIOC
#define PIN_CDC_LED                     GPIO_PIN_13
#define PIN_CDC_LED_Bit                 13

#define PIN_MSC_LED_PORT                GPIOC
#define PIN_MSC_LED                     GPIO_PIN_13
#define PIN_MSC_LED_Bit                 13

#endif // __IO_CONFIG_H__
