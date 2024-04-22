#include <stdio.h>
#include "uart.h"
#include "gpio.h"



int main(){

	uart_send('A');
	printf( "%c\n", 'B');
	
	return 0;



}

