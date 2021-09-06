/*
 * Name: Zackary McClamma
 * Course: ECE 532
 * Assignment: Homework 4
 * Date: 28 OCT 2019
 * File: hw4.h
 *
 * */

#ifndef HW4_H_
#define HW4_H_

typedef volatile struct{
	unsigned int uart_rxdata;
	unsigned int uart_txdata;
	unsigned int uart_status;
	unsigned int uart_control;
	unsigned int uart_divisor;
	unsigned int uart_eop;
}uart_reg;


void uartPrint(char* input);



#endif /* HW4_H_ */
