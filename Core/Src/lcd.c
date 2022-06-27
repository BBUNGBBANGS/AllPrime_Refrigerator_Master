#include "lcd.h"
#include "string.h"
#include "stdio.h"

char LCD_Tx_Buf[100];

static void LCD_Transmit_Command(char cmd);
static void LCD_Cursor(char col, char row);
static void LCD_Transmit_Data(char data);
static void LCD_Data_Output(uint8 data);

void LCD_Init(void)
{
	LCD_Transmit_Command(0x3F); // Function Set , 2-Line Mode
    HAL_Delay(10);
	//LCD_Transmit_Command(0x30); // Function Set , 2-Line Mode
    //HAL_Delay(1);	
	//LCD_Transmit_Command(0x30); // Function Set , 2-Line Mode
    //HAL_Delay(1);
	//LCD_Transmit_Command(0x0C); // Display ON
    //HAL_Delay(10);
	//LCD_Transmit_Command(0x06); // Increment Mode
    //HAL_Delay(10);
	//LCD_Transmit_Command(0x01); // Display Clear
    //HAL_Delay(10);
}
uint8 test_data = 0x0; 
uint8 test_x;
uint8 test_y;
void LCD_Control(void)
{
    test_data++;
    test_x++;
    test_y++;
    if(test_x>7)
    {
        test_x = 0;
    }
    if(test_y>63)
    {
        test_y = 0;
    }
    LCD_Transmit_Command(0xB8|test_x);
    LCD_Transmit_Data(test_data);
    //LCD_Transmit_Command(0x40|test_y);
    //LCD_Transmit_Data(test_data);
}

static void LCD_Transmit_Command(char cmd)
{
    HAL_GPIO_WritePin(LCD_RS_GROUP,LCD_RS_PIN,LCD_OFF);
	//HAL_GPIO_WritePin(LCD_RW_GROUP,LCD_RW_PIN,LCD_OFF);
    HAL_GPIO_WritePin(LCD_E_GROUP,LCD_E_PIN,LCD_ON);
    HAL_GPIO_WritePin(LCD_CS1_GROUP,LCD_CS1_PIN,LCD_ON);
    HAL_GPIO_WritePin(LCD_CS2_GROUP,LCD_CS2_PIN,LCD_ON);   
    HAL_Delay(1);
	LCD_Data_Output(cmd); 
    HAL_GPIO_WritePin(LCD_E_GROUP,LCD_E_PIN,LCD_OFF);
    HAL_GPIO_WritePin(LCD_CS1_GROUP,LCD_CS1_PIN,LCD_OFF);
    HAL_GPIO_WritePin(LCD_CS2_GROUP,LCD_CS2_PIN,LCD_OFF);   
    HAL_Delay(1);
}

static void LCD_Cursor(char col, char row)
{
	LCD_Transmit_Command(0x80 | (row + col * 0x40));
}

static void LCD_Transmit_Data(char data)
{
	HAL_GPIO_WritePin(LCD_RS_GROUP,LCD_RS_PIN,LCD_ON);
	//HAL_GPIO_WritePin(LCD_RW_GROUP,LCD_RW_PIN,LCD_OFF);
    HAL_GPIO_WritePin(LCD_E_GROUP,LCD_E_PIN,LCD_ON);
    HAL_GPIO_WritePin(LCD_CS1_GROUP,LCD_CS1_PIN,LCD_ON);
    HAL_GPIO_WritePin(LCD_CS2_GROUP,LCD_CS2_PIN,LCD_ON);   
    HAL_Delay(1);
	LCD_Data_Output(data);
    HAL_GPIO_WritePin(LCD_E_GROUP,LCD_E_PIN,LCD_OFF);
    HAL_GPIO_WritePin(LCD_CS1_GROUP,LCD_CS1_PIN,LCD_OFF);
    HAL_GPIO_WritePin(LCD_CS2_GROUP,LCD_CS2_PIN,LCD_OFF);   
    HAL_Delay(1);
}

static void LCD_Data_Output(uint8 data)
{
    uint8 d0,d1,d2,d3,d4,d5,d6,d7;

    d0 = data & 0x01;
    d1 = (data >> 1) & 0x01;
    d2 = (data >> 2) & 0x01;
    d3 = (data >> 3) & 0x01;
    d4 = (data >> 4) & 0x01;
    d5 = (data >> 5) & 0x01; 
    d6 = (data >> 6) & 0x01;
    d7 = (data >> 7) & 0x01;

    if(d0>0)
    {
        HAL_GPIO_WritePin(LCD_D0_GROUP,LCD_D0_PIN,LCD_ON);
    }
    else
    {
        HAL_GPIO_WritePin(LCD_D0_GROUP,LCD_D0_PIN,LCD_OFF);
    }
    if(d1>0)
    {
        HAL_GPIO_WritePin(LCD_D1_GROUP,LCD_D1_PIN,LCD_ON);
    }
    else
    {
        HAL_GPIO_WritePin(LCD_D1_GROUP,LCD_D1_PIN,LCD_OFF);
    }
    if(d2>0)
    {
        HAL_GPIO_WritePin(LCD_D2_GROUP,LCD_D2_PIN,LCD_ON);
    }
    else
    {
        HAL_GPIO_WritePin(LCD_D2_GROUP,LCD_D2_PIN,LCD_OFF);
    }
    if(d3>0)
    {
        HAL_GPIO_WritePin(LCD_D3_GROUP,LCD_D3_PIN,LCD_ON);
    }
    else
    {
        HAL_GPIO_WritePin(LCD_D3_GROUP,LCD_D3_PIN,LCD_OFF);
    }
    if(d4>0)
    {
        HAL_GPIO_WritePin(LCD_D4_GROUP,LCD_D4_PIN,LCD_ON);
    }
    else
    {
        HAL_GPIO_WritePin(LCD_D4_GROUP,LCD_D4_PIN,LCD_OFF);
    }
    if(d5>0)
    {
        HAL_GPIO_WritePin(LCD_D5_GROUP,LCD_D5_PIN,LCD_ON);
    }
    else
    {
        HAL_GPIO_WritePin(LCD_D5_GROUP,LCD_D5_PIN,LCD_OFF);
    }
    if(d6>0)
    {
        HAL_GPIO_WritePin(LCD_D6_GROUP,LCD_D6_PIN,LCD_ON);
    }
    else
    {
        HAL_GPIO_WritePin(LCD_D6_GROUP,LCD_D6_PIN,LCD_OFF);
    }
    if(d7>0)
    {
        HAL_GPIO_WritePin(LCD_D7_GROUP,LCD_D7_PIN,LCD_ON);
    }
    else
    {
        HAL_GPIO_WritePin(LCD_D7_GROUP,LCD_D7_PIN,LCD_OFF);
    }
}