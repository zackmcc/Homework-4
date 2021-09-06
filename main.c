/*
 * Name: Zackary McClamma
 * Course: ECE 532
 * Assignment: Homework 4
 * Date: 28 OCT 2019
 * File: main.c
 *
 * */


#include <stdio.h>
#include "system.h"
#include "includes.h"
#include "altera_avalon_uart_regs.h"
#include "hw4.h"


/* Definition of Task Stacks */
#define   TASK_STACKSIZE       2048
OS_EVENT *tex;

OS_STK    task1_stk[TASK_STACKSIZE];
OS_STK    task2_stk[TASK_STACKSIZE];

/* Definition of Task Priorities */

#define TASK1_PRIORITY      2
#define TASK2_PRIORITY      3

/* Prints "Hello World" and sleeps for three seconds */
void task1(void* pdata)
{
  INT8U err;

  while (1)
  { 
	OSMutexPend(tex, 0, &err);
    uartPrint("abcdefghijklmnopqrstuvwxyz \n");
    OSTimeDlyHMSM(0, 0, 0, 5);
    OSMutexPost(tex);


  }
}
/* Prints "Hello World" and sleeps for three seconds */
void task2(void* pdata)
{
  INT8U err;

  while (1)
  { 
	OSMutexPend(tex, 0, &err);
    uartPrint("ABCDEFGHIJKLMNOPQRSTUVWXYZ \n");
    OSTimeDlyHMSM(0, 0, 0, 10);
    OSMutexPost(tex);


  }
}
/* The main function creates two task and starts multi-tasking */
int main(void)
{
  INT8U err;
  tex = OSMutexCreate(1, &err);
  OSTaskCreateExt(task1,
                  NULL,
                  (void *)&task1_stk[TASK_STACKSIZE-1],
                  TASK1_PRIORITY,
                  TASK1_PRIORITY,
                  task1_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0);
              
               
  OSTaskCreateExt(task2,
                  NULL,
                  (void *)&task2_stk[TASK_STACKSIZE-1],
                  TASK2_PRIORITY,
                  TASK2_PRIORITY,
                  task2_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0);
  OSStart();
  return 0;
}


void uartPrint(char* input){

	uart_reg *reg = UART_0_BASE;
	do{
		while((reg->uart_status & 0x00000040) == 0x00);
		reg->uart_txdata = *input;
		input = input + 1;
	} while (*input != '\0');

	reg->uart_txdata = '\0';
	return;

}
