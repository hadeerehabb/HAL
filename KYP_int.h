/*
 * KYP.int.h
 *
 *  Created on: May 30, 2022
 *      Author: weza
 */

#ifndef HAL_KYD_KYP_INT_H_
#define HAL_KYD_KYP_INT_H_
#include"../../LIB/STD_TYPES.h"
#define COL_START 0
#define COL_END 3
#define ROW_START 4
#define ROW_END 7
#define KYD_PORT DIO_PORTA
#define OUTPUT_DISPLAY PORTB
void HKYP_Vinit(void);
//U8 HKYP_u8IfPressed(void);
U8 HKYP_u8IfPressed(U8 *A_U8PtrToCol,U8 *A_U8PtrToRow);
#endif /* HAL_KYD_KYP_INT_
H_ */
