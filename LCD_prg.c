/*
 * LCD_prg.c
 *
 *  Created on: May 31, 2022
 *      Author: weza
 */

#include<util/delay.h>

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_int.h"
#include "../../HAL/LCD/LCD_config.h"
#include "../../HAL/LCD/LCD_int.h"
#include "../../HAL/LCD/LCD_Private.h"
void HLCD_voidInit(void){
	DIO_vWrtPortDir(DATA_PORT,PORT_OUTPUT);
	DIO_vWrtPinDir(CONTROL_PORT,RS_BIT,DIO_OUTPUT);
	DIO_vWrtPinDir(CONTROL_PORT,RW_BIT,DIO_OUTPUT);
	DIO_vWrtPinDir(CONTROL_PORT,ENABLE_BIT,DIO_OUTPUT);
	_delay_ms(30); /* Delay 30ms to ensure the initialization of the LCD driver */
	 HLCD_voidSendCommand(CMD_RETURN_HOME); _delay_ms(15); /* Return Home */
		/* Function Set */
	 HLCD_voidSendCommand(CMD_SET_8BITS_2LINES); _delay_ms(1); /* Configure as 8-bit data mode*/
	 HLCD_voidSendCommand(CMD_DISPLAY_ON);	_delay_ms(1);  /* Display ON OFF Control */
	 HLCD_voidSendCommand(CMD_CLEAR);      _delay_ms(2); /* Clear Display */
	 HLCD_voidSendCommand(CMD_ENTRY_MODE); _delay_ms(2);  /* Entry Mode*/

}
void HLCD_voidSendCommand(U8 A_u8Cmd){
	 DIO_vWrtPinVal(CONTROL_PORT,RS_BIT,DIO_LOW);
	 DIO_vWrtPinVal(CONTROL_PORT,RW_BIT,DIO_LOW);
	 DIO_vWrtPortVal(DATA_PORT,A_u8Cmd);
	 DIO_vWrtPinVal(CONTROL_PORT,ENABLE_BIT,DIO_HIGH);
		_delay_ms(1);
	 DIO_vClrPinVal(CONTROL_PORT,ENABLE_BIT);
	 //_delay_ms(10);

}
void HLCD_voidSendData(U8 A_u8Data){
	 DIO_vWrtPinVal(CONTROL_PORT,RS_BIT,DIO_HIGH);
	 DIO_vWrtPinVal(CONTROL_PORT,RW_BIT,DIO_LOW);
	 DIO_vSetPinVal(CONTROL_PORT,ENABLE_BIT);
	 _delay_ms(1);
	 DIO_vWrtPortVal(DATA_PORT,A_u8Data);
	 DIO_vWrtPinVal(CONTROL_PORT,ENABLE_BIT,DIO_HIGH);
	_delay_ms(1);
	 DIO_vWrtPinVal(CONTROL_PORT,ENABLE_BIT,DIO_LOW);
	 _delay_ms(10);
}
void HLCD_voidWrtOnCGRAM(U8 A_U8PatternINDX,U8 *A_U8PatternVal,U8 A_U8DesiredRow, U8 A_U8DesiredCol){
	U8 L_U8CGRAMAddress=0;
 L_U8CGRAMAddress=SET_CGRAM_ADDRESS+A_U8PatternINDX*8; //set cgram address in n pattern
 HLCD_voidSendCommand( L_U8CGRAMAddress);         // to send the address counter command
 for(U8 L_U8ArrayCounter=0; L_U8ArrayCounter<8; L_U8ArrayCounter++){
		HLCD_voidSendData(A_U8PatternVal[L_U8ArrayCounter]); //write data in the pattern
	}// concept 1st:set address counter at the CGRAM pattern address,2nd write data in cgram,3rd set address of the pattern of the cgram to the ddram to make the address counter points to it and display the data
// I/D bit control the bit of the pattern and increment untill the pattern is all written
HLCD_voidSendCommand(CMD_ENTRY_MODE);
 //HLCD_voidSendCommand(ORIG_DDRAM_ADR);//return the address counter to the DDRAM
	HLCD_voidGOTO( A_U8DesiredRow,A_U8DesiredCol);
	 HLCD_voidSendData(PATTERN0);
}
void HLCD_voidDisplayString(U8 *PA_U8STRING){ // el astrix elgnb el arg m3naha arraY
	U8 L_u8Counter=0;
	while(PA_U8STRING[L_u8Counter]!='\0'){
		HLCD_voidSendData(PA_U8STRING[L_u8Counter]);
		L_u8Counter++;
	}
}
void HLCD_voidCLR(void){
	HLCD_voidSendCommand(CLR_COMMAND);
}

void HLCD_voidGOTO(U8 A_u8DesiredRow,U8 A_u8DesiredCol){
	U8 L_DDRAM_ADDRESS=0;
	U8 L_U8COMMAND;
	if((A_u8DesiredRow<MAX_ROW_IND)&&(A_u8DesiredCol<MAX_COL_IND)){
		if(A_u8DesiredRow==FIRST_ROW_START){
			L_DDRAM_ADDRESS=FIRST_ROW_START+A_u8DesiredCol;
		}
		else {L_DDRAM_ADDRESS=SEC_ROW_START+A_u8DesiredCol;}
		L_U8COMMAND=L_DDRAM_ADDRESS+ORIG_DDRAM_ADR;
		HLCD_voidSendCommand(L_U8COMMAND);
	}
}
void HLCD_voidSendInt(U32 Integer){
	if(Integer!=0){
		HLCD_voidSendInt(Integer/10); // HYFDAL Y2SM W  YKHZN FEL STACK
		HLCD_voidSendData((Integer%10)+'0');
	}
}


