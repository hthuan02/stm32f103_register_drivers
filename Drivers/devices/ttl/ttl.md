# USART DEBUG USES TTL MODULE

_Use Hercules application to display_

## 1. PC & STM32 (2 dimension comunication)

**Flow:**

- Hercules transmit char `'S'` or `'T'` for STM32.
- STM32 **receive char** 
    + `'S'`: Turn on the led.
    + `'T'`: Turn off the led.
    + Other: Try again...
- After STM32 will **transmit string** on hercules screen.

```c
int main (void)
{
	uint32_t data_rx = 0;

	rcc_init();

	gpio_init();
	/* Reset led */
	GPIOA->BSRR = (3UL << 9U);


	timer2_init();
	usart2_init();
	usart2_frame_config();

	while (1)
	{	
		data_rx = usart2_receive_char();

		// if (data_rx == 'S')
		// {
		// 	GPIOA->BRR = (3UL << 9U);
		// 	usart2_transmit_string("TURN ON LED PA9 PA10 \r\n");
		// }

		// else if (data_rx == 'T')
		// {
		// 	GPIOA->BSRR = (3UL << 9U);
		// 	usart2_transmit_string("TURN OFF LED PA9 PA10 \r\n");
		// }
		
		switch (data_rx)
		{
		case 'S':
			GPIOA->BRR = (3UL << 5U);
			usart2_transmit_string("- Turn on the led PA9 & PA10\n");	
			break;
		
		case 'T':
			GPIOA->BSRR = (3UL << 5U);
			usart2_transmit_string("- Turn off the led PA9 & PA10\n");
			break;

		default:
			usart2_transmit_string("- Please try again!\n");
			break;
		}

	}
}
```

## 2. STM32 & STM32 (2 dimension comunication)