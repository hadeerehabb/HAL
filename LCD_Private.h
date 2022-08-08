/*
 * LCD_Private.h
 *
 *  Created on: May 31, 2022
 *      Author: weza
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_
#define CMD_CLEAR             (0x01) /* replace all characters with ASCII 'space'     */
#define CMD_RETURN_HOME       (0x02) /* return cursor to first position on first line */
#define CMD_ENTRY_MODE        (0x06) /* shift cursor from left to right on read/write */
#define CMD_DISPLAY_OFF       (0x08) /* turn display off                              */
#define CMD_DISPLAY_ON        (0x0C) /* display on, cursor off, don't blink character */
#define CMD_RESET       	  (0x30) /* reset the LCD                                 */
#define CMD_SET_8BITS_2LINES  (0x38) /* 8-bit data, 2-line display, 5 x 7 font        */
#define CMD_SET_4BITS_2LINES  (0x28) /* 4-bit data, 2-line display, 5 x 7 font        */
#define CMD_CURSOR_OFFSET     (0x80) /* set cursor position                           */
#define CMD_FUNCTION_SET      (0b00110000)
#define CGRAM_DIVISION 8
#define ORIG_DDRAM_ADR 0b10000000
#define FIRST_ROW_START 0b00000000
#define SEC_ROW_START 0x40
#define SET_CGRAM_ADDRESS 0x40
#define CLR_COMMAND 0b00000001
#define RETURN_HOME_COMMAND 0b00000010
 #define PATTERN0 0
 #define PATTERN1 1
 #define PATTERN2 2
 #define PATTERN3 3
 #define PATTERN4 4
 #define PATTERN5 5
 #define PATTERN6 6
 #define PATTERN7 7

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
