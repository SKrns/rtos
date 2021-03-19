#include "stdint.h"
#include "stdbool.h"
#include "HalUart.h"
#include "HalInterrupt.h"
#include "HalTimer.h"

#include "stdio.h"
#include "stdlib.h"
#include "kernel.h"
#include "task.h"

static void Hw_init(void);
static void Timer_test(void);

void User_task0(void);
void User_task1(void);
void User_task2(void);
static void Kernel_init(void);

void main(void)
{
	Hw_init();

	uint32_t i = 100;
	while(i--)
	{
		Hal_uart_put_char('N');
	}

	Hal_uart_put_char('\n');

	putstr("Hello World!\n");

    Kernel_init();
	// Timer_test();

}

static void Hw_init(void)
{
	Hal_interrupt_init();
	Hal_uart_init();
	Hal_timer_init();

}

static void Kernel_init(void)
{
    uint32_t taskId;

    Kernel_task_init();

    taskId = Kernel_task_create(User_task0);
    if (NOT_ENOUGH_TASK_NUM == taskId)
    {
        putstr("Task0 creation fail\n");
    }

    taskId = Kernel_task_create(User_task1);
    if (NOT_ENOUGH_TASK_NUM == taskId)
    {
        putstr("Task1 creation fail\n");
    }

    taskId = Kernel_task_create(User_task2);
    if (NOT_ENOUGH_TASK_NUM == taskId)
    {
        putstr("Task2 creation fail\n");
    }

    Kernel_task_start();
}

static void Timer_test(void)
{
    while(true)
    {
        Hal_uart_put_char("tick \n");
        delay(1000);
    }
}

void User_task0(void)
{
    uint32_t local = 0;

    while(true)
    {
    
    putstr("User Task #0\n");
    Kernel_yield();

    }
}

void User_task1(void)
{
    uint32_t local = 0;

    while(true)
    {
    
    putstr("User Task #1\n");
    Kernel_yield();

    }
}

void User_task2(void)
{
    uint32_t local = 0;

    while(true)
    {
    
    putstr("User Task #2\n");
    Kernel_yield();

    }
}

