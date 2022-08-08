/*
 * LCD_config.h
 *
 *  Created on: May 31, 2022
 *      Author: weza
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#define LCD_BIT_MODE 8BIT
#define DATA_PORT DIO_PORTC
#define CONTROL_PORT DIO_PORTD
#define RS_BIT DIO_PIN0
#define RW_BIT DIO_PIN1
#define ENABLE_BIT DIO_PIN2
#define MAX_COL_IND 16
#define MAX_ROW_IND 2

#endif /* HAL_LCD_LCD_CONFIG_H_ */
