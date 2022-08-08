/*
 * LCD_int.h
 *
 *  Created on: May 31, 2022
 *      Author: weza
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_
#include "../../HAL/LCD/LCD_config.h"
#include "../../HAL/LCD/LCD_Private.h"
#include "../../LIB/STD_TYPES.h"
void HLCD_voidInit(void);
void HLCD_voidGOTO(U8 A_u8DesiredRow,U8 A_u8DesiredCol);

void HLCD_voidCLR(void);
void HLCD_voidDisplayString(U8 *PA_U8STRING);
void HLCD_voidSendData(U8 A_u8Data);
void HLCD_voidSendCommand(U8 A_u8Cmd);
void HLCD_voidWrtOnCGRAM(U8 A_U8PatternINDX,U8 *A_U8PatternVal,U8 A_U8DesiredRow, U8 A_U8DesiredCol);
void HLCD_voidSendInt(U32 Integer);
#endif /* HAL_LCD_LCD_INT_H_ */
