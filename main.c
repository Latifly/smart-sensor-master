/*
 * main.c
 *
 *  Created on: Dec 12, 2019
 *      Author: Alatif
 */

#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <util/delay.h>
#include "uart.h"
#include "spi.h"

uint8_t sHigh0=0, sLow0=0;
uint8_t sHigh1=0, sLow1=0;
uint8_t sHigh2=0, sLow2=0;
uint16_t sFull0=0, sFull1=0, sFull2=0;

/* variable digitalRaw	*/
uint8_t tHigh0=0, tLow0=0;
uint8_t tHigh1=0, tLow1=0;
uint8_t tHigh2=0, tLow2=0;
uint16_t tFull0=0, tFull1=0, tFull2=0;

uint8_t debounce=0xFF;
uint8_t data, command;
int main(){
	SPI_MasterInit();
	USART_Init();

	while(1){
		//		command=USART_GetChar();
		//		data=SPI_MasterTransmit(0x10);
		//		USART_PutNum(data);

		//		USART_PutStr("analogRaw: ");
		SPI_MasterTransmit(0x10);
		_delay_us(500);
		sLow0 = SPI_MasterTransmit(0x11);
		_delay_us(500);
		sHigh0 = SPI_MasterTransmit(0x12);
		_delay_us(500);
		sLow1 = SPI_MasterTransmit(0x13);
		_delay_us(500);
		sHigh1 = SPI_MasterTransmit(0x14);
		_delay_us(500);
		sLow2 = SPI_MasterTransmit(0x15);
		_delay_us(500);
		sHigh2 = SPI_MasterTransmit(0x00);
		_delay_us(500);

		sFull0=(sHigh0*256)+sLow0;
		sFull1=(sHigh1*256)+sLow1;
		sFull2=(sHigh2*256)+sLow2;

		USART_PutStr("S0: high="); USART_PutNum(sHigh0); USART_PutStr(" low="); USART_PutNum(sLow0); USART_PutStr(" full="); USART_PutNum(sFull0); USART_PutStr("	");
		USART_PutStr("S1: high="); USART_PutNum(sHigh1); USART_PutStr(" low="); USART_PutNum(sLow1); USART_PutStr(" full="); USART_PutNum(sFull1); USART_PutStr("	");
		USART_PutStr("S2: high="); USART_PutNum(sHigh2); USART_PutStr(" low="); USART_PutNum(sLow2); USART_PutStr(" full="); USART_PutNum(sFull2); USART_PutStr("\n");
		//
		//
		//			sFull0 = (sHigh0 << 8) | sLow0;
		//			sFull1 = (sHigh1 << 8) | sLow1;
		//			sFull2 = (sHigh2 << 8) | sLow2;
		//
		//			USART_PutNum(sHigh0); USART_PutStr("^"); USART_PutNum(sLow0); USART_PutStr("^"); USART_PutNum(sFull0);
		//			USART_PutStr(" - ");
		//			USART_PutNum(sHigh1); USART_PutStr("^"); USART_PutNum(sLow1); USART_PutStr("^"); USART_PutNum(sFull1);
		//			USART_PutStr(" - ");
		//			USART_PutNum(sHigh2); USART_PutStr("^"); USART_PutNum(sLow2); USART_PutStr("^"); USART_PutNum(sFull2);;
		//		USART_PutStr("\n");

		//		USART_PutStr("analogRaw: ");
		//		SPI_MasterTransmit(0x10);
		//		_delay_us(500);
		//		sLow0 = SPI_MasterTransmit(0x00);
		//		_delay_us(500);
		//
		//		USART_PutNum(sLow0); USART_PutStr("\n");
	}
}
