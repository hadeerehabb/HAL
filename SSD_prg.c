/*
 * SSD_prg.c
 *
 *  Created on: May 31, 2022
 *      Author: weza
 */
/*
 * SSD_prg.c

 *
 *  Created on: May 22, 2022
 *      Author: weza
 */
#include <avr/io.h>

#include "../../HAL/SSD/SSD_config.h"
#include "../../HAL/SSD/SSD_int.h"
#include "../../HAL/SSD/SSD_private.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
void HSSD_vInit(){
	DIO_vWrtPortDir(SSD_PORT_ID1,PORT_OUTPUT);
	DIO_vWrtPortDir(SSD_PORT_ID2,PORT_OUTPUT);
}
void HSSD_U8SetValueInSSD(U8 A_U8SSDId,U8 A_U8Data)
{
#if SSD_TYPE==COMMIN_CATHODE
	switch(A_U8SSDId){
	case SSD_ID1: DIO_vWrtPortVal(SSD_PORT_ID1,A_U8Data); break;
	case SSD_ID2: DIO_vWrtPortVal(SSD_PORT_ID2,A_U8Data); break;
	default: break;}
#else
	switch(A_U8SSDId){
		case SSD_ID1: DIO_vWrtPortVal(SSD_PORT_ID1,~A_U8Data); break;
		case SSD_ID2: DIO_vWrtPortVal(SSD_PORT_ID2,~A_U8Data); break;
		default: break;}
#endif
}
void HSSD_U8ClrValueInSSD(U8 A_U8SSDId)
{
	#if SSD_TYPE==COMMIN_CATHODE
	switch(A_U8SSDId){
	case SSD_ID1: DIO_vWrtPortVal(SSD_PORT_ID1,PORT_LOW); break;
	case SSD_ID2: DIO_vWrtPortVal(SSD_PORT_ID2,PORT_LOW); break;
	default: break;}
#else
	switch(A_U8SSDId){
		case SSD_ID1: DIO_vWrtPortVal(SSD_PORT_ID1,PORT_HIGH); break;
		case SSD_ID2: DIO_vWrtPortVal(SSD_PORT_ID2,PORT_HIGH); break;
		default: break;}
#endif
}

