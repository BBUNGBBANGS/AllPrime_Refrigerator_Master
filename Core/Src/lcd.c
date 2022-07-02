#include "lcd.h"
#include "string.h"
#include "stdio.h"

char LCD_Tx_Buf[100];

static void LCD_Transmit_Command(char cmd);
static void LCD_Cursor(char col, char row);
static void LCD_Transmit_Data(char data);
static void LCD_Data_Output(uint8 data);
/* 5x7 Font including 1 space to display HELLO WORLD */
char H[]={0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00};
char E[]={0x7F, 0x49, 0x49, 0x49, 0x41, 0x00};
char L[]={0x7F, 0x40, 0x40, 0x40, 0x40, 0x00};
char O[]={0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00};

char W[]={0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00};
char R[]={0x7F, 0x09, 0x19, 0x29, 0x46, 0x00};
char D[]={0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00};

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
uint8 test_data = 0xff; 
uint8 test_x = 0;
uint8 test_y;
uint8 test_word;
void LCD_Control(void)
{
    //test_data++;
    //test_x++;
    //test_y++;
    if(test_y>7)
    {
        test_y = 0;
    }
    if(test_x>63)
    {
        test_x = 0;
    }
    LCD_Transmit_Command(0xB8|test_y);
    LCD_Transmit_Command(0x40|(test_word*5));
    for(uint8 i = 0u;i<6;i++)
    {
        switch(test_word)
        {
            case 0 :
                LCD_Transmit_Data(H[i]);
            break;
            case 1 :
                LCD_Transmit_Data(E[i]);
            break;
            case 2 :
                LCD_Transmit_Data(L[i]);
            break;
            case 3 :
                LCD_Transmit_Data(L[i]);
            break;
            case 4 :
                LCD_Transmit_Data(O[i]);
            break;
            case 5 :
                LCD_Transmit_Data(0);
            break;
            case 6 :
                LCD_Transmit_Data(W[i]);
            break;
            case 7 :
                LCD_Transmit_Data(O[i]);
            break;
            case 8 :
                LCD_Transmit_Data(R[i]);
            break;
            case 9 :
                LCD_Transmit_Data(L[i]);
            break;
            case 10 :
                LCD_Transmit_Data(D[i]);
            break;
            case 11 :
                LCD_Transmit_Data(0);
            break;
        }
    }
    test_word++;
    if(test_word>11)
    {
        test_word = 0;
    }
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