/*
 * KYP_prg.c

 *
 *  Created on: May 30, 2022
 *      Author: weza
 */
#include <avr/io.h>
#include<util/delay.h>

#include "../../HAL/KYD/KYP_int.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_int.h"

void HKYP_Vinit(void){
	u8 L_U8RowCounter;
	u8 L_U8ColCounter;
	for(L_U8RowCounter=ROW_START;L_U8RowCounter<=ROW_END;L_U8RowCounter++){
		DIO_vWrtPinDir(KYD_PORT,L_U8RowCounter,DIO_INPUT);
		DIO_vWrtPinVal(KYD_PORT,L_U8RowCounter,DIO_HIGH);
	}
	for(L_U8ColCounter=COL_START;L_U8ColCounter<=COL_END;L_U8ColCounter++){
			DIO_vWrtPinDir(KYD_PORT,L_U8ColCounter,DIO_OUTPUT);
			DIO_vWrtPinVal(KYD_PORT,L_U8ColCounter,DIO_HIGH);
		}
}

//U8 HKYP_u8IfPressed(void){
//	U8 L_IfPressed=0;
//	U8 L_U8RowIdx=0;
//    U8 L_U8ColIdx=0;
//    U8 L_U8OutPut=0;
//	for(L_U8ColIdx=COL_START;L_U8ColIdx<=COL_END;L_U8ColIdx++){
//		DIO_vWrtPinVal(KYD_PORT,L_U8ColIdx,DIO_LOW); //activate current col
//		for(L_U8RowIdx=ROW_START;L_U8RowIdx<=ROW_END;L_U8RowIdx++){
//			L_IfPressed=DIO_U8GetPinVal(KYD_PORT, L_U8RowIdx);
//         if( L_IfPressed==0){
//        	L_IfPressed=DIO_U8GetPinVal(KYD_PORT, L_U8RowIdx);
//        	_delay_ms(20);
//        	while( L_IfPressed==0){
//        		L_IfPressed=DIO_U8GetPinVal(KYD_PORT, L_U8RowIdx);
//        	}//wait until released
//        	L_U8OutPut=G_Array_Mapping[L_U8ColIdx][L_U8RowIdx-4];
//        	OUTPUT_DISPLAY=L_U8OutPut;
//         }
//		}
//
//		DIO_vSetPinVal(KYD_PORT,L_U8ColIdx);
//	}
//
//return OUTPUT_DISPLAY;
//}
U8 HKYP_u8IfPressed(U8 *A_U8PtrToCol,U8 *A_U8PtrToRow){
	U8 L_IfPressed=0;
		U8 L_U8RowIdx=0;
	    U8 L_U8ColIdx=0;
	   static  U8 L_U8pressed=0;
		for(L_U8ColIdx=COL_START;L_U8ColIdx<=COL_END;L_U8ColIdx++){
			DIO_vWrtPinVal(KYD_PORT,L_U8ColIdx,DIO_LOW); //activate current col
			for(L_U8RowIdx=ROW_START;L_U8RowIdx<=ROW_END;L_U8RowIdx++){
				L_IfPressed=DIO_U8GetPinVal(KYD_PORT, L_U8RowIdx);
	         if( L_IfPressed==0){
	        	L_IfPressed=DIO_U8GetPinVal(KYD_PORT, L_U8RowIdx);
	        	_delay_ms(20);
	        	while( L_IfPressed==0){
	        		L_IfPressed=DIO_U8GetPinVal(KYD_PORT, L_U8RowIdx);
	        	}//wait until released
	        	L_U8pressed=1;
	        	*A_U8PtrToCol= L_U8ColIdx;
	        	*A_U8PtrToRow=L_U8RowIdx-4;
	         }
}
			DIO_vSetPinVal(KYD_PORT,L_U8ColIdx);
		}

		return L_U8pressed; // kieda ana pressed w shellt ede khlas
}


