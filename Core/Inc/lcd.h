#ifndef _LCD_H
#define _LCD_H

#include "main.h"

#define LCD_RS_GROUP            (GPIOA)
#define LCD_E_GROUP             (GPIOB)
#define LCD_D0_GROUP            (GPIOB)
#define LCD_D1_GROUP            (GPIOB)
#define LCD_D2_GROUP            (GPIOB)
#define LCD_D3_GROUP            (GPIOB)
#define LCD_D4_GROUP            (GPIOA)
#define LCD_D5_GROUP            (GPIOA)
#define LCD_D6_GROUP            (GPIOA)
#define LCD_D7_GROUP            (GPIOA)
#define LCD_CS1_GROUP           (GPIOA)
#define LCD_CS2_GROUP           (GPIOC)

#define LCD_RS_PIN              (GPIO_PIN_9)
#define LCD_E_PIN               (GPIO_PIN_1)
#define LCD_D0_PIN              (GPIO_PIN_0)
#define LCD_D1_PIN              (GPIO_PIN_3)
#define LCD_D2_PIN              (GPIO_PIN_4)
#define LCD_D3_PIN              (GPIO_PIN_5)
#define LCD_D4_PIN              (GPIO_PIN_11)
#define LCD_D5_PIN              (GPIO_PIN_12)
#define LCD_D6_PIN              (GPIO_PIN_2)
#define LCD_D7_PIN              (GPIO_PIN_3)
#define LCD_CS1_PIN             (GPIO_PIN_15)
#define LCD_CS2_PIN             (GPIO_PIN_13)

#define LCD_ON                  (GPIO_PIN_SET)
#define LCD_OFF                 (GPIO_PIN_RESET)

extern void LCD_Init(void);
extern void LCD_Control(void);

#endif
