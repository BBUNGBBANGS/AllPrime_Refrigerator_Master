#ifndef _SWITCH_H
#define _SWITCH_H

#include "main.h"

#define KEYPAD_NUM_DEFAULT (' ')
#define KEYPAD_NUM_1	('*')//('D')
#define KEYPAD_NUM_2	('0')//('#')
#define KEYPAD_NUM_3	('D')//('0')
#define KEYPAD_NUM_4	('#')//('*')
#define KEYPAD_NUM_5	('4')//('C')
#define KEYPAD_NUM_6	('5')//('9')
#define KEYPAD_NUM_7	('6')//('8')
#define KEYPAD_NUM_8	('B')//('7')
#define KEYPAD_NUM_9	('7')//('B')
#define KEYPAD_NUM_10	('8')//('6')
#define KEYPAD_NUM_11	('9')//('5')
#define KEYPAD_NUM_12	('C')//('4')
#define KEYPAD_NUM_13	('1')//('A')
#define KEYPAD_NUM_14	('2')//('3')
#define KEYPAD_NUM_15	('A')//('2')
#define KEYPAD_NUM_16	('3')//('1')

#define KEYPAD_DEBOUNCE	(50u) // 50ms in 1ms task

extern uint8 keypadnum;

extern void Key_Scan(void);

#endif