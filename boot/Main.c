#include "stdint.h"
#include "stdbool.h"
#include "HalUart.h"
#include "HalInterrupt.h"
#include "HalTimer.h"

#include "stdio.h"
#include "stdlib.h"

static void Hw_init(void);
static void Timer_test(void);

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

	Timer_test();

}

static void Hw_init(void)
{
	Hal_interrupt_init();
	Hal_uart_init();
	Hal_timer_init();

}

static void Timer_test(void)
{
    while(true)
    {
        Hal_uart_put_char("tick \n");
        delay(1000);
    }
}