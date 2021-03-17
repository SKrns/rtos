#include "stdint.h"
#include "stdbool.h"
#include "HalUart.h"
#include "HalInterrupt.h"

#include "stdio.h"

static void Hw_init(void);

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


	while(true);

}

static void Hw_init(void)
{
	Hal_interrupt_init();
	Hal_uart_init();
}

