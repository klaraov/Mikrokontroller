#include "gpio.h"
#include "uart.h"




void uart_init(){
	
	GPIO->PIN_CNF[8] = 1;
	//RX mottar port 08
	
	GPIO->PIN_CNF[6] = 0;
	//TX sender port 06
	
	UART->PSELTXD = 6;
	UART->PSELRXD = 8;
	
	UART->PSELRTS = 0xFFFFFFFF;
	UART->PSELCTS = 0xFFFFFFFF;
	
	UART->BAUDRATE = 0x00275000;
	UART->ENABLE = (1<<2); //4
	UART->TASKS_STARTRX = 1;
	

}


void uart_send(char letter){
	
	UART->TASKS_STARTTX =1;
	
	UART->TXD = letter;
	
	while (UART->EVENTS_TXDRDY != 1){
		//do fuck all<33	
	}
	UART->TASKS_STOPTX =1;
	UART->EVENTS_TXDRDY = 0;

}

char uart_read(){
	UART->TASKS_STARTRX = 1;
	UART->EVENTS_RXDRDY= 0;
	
	if (UART->EVENTS_RXDRDY ==1){
		return (UART->RXD);
	}
	else{
		return '\0';
	}		

}











