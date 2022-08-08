/*
 * SSD_int.h
 *
 *  Created on: May 31, 2022
 *      Author: weza
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_
#include"../../LIB/STD_TYPES.h"
void HSSD_vInit();
void HSSD_U8SetValueInSSD(U8 A_U8SSDId,U8 A_U8Data);
void HSSD_U8ClrValueInSSD(U8 A_U8SSDId);
#endif /* HAL_SSD_SSD_INT_H_ */
