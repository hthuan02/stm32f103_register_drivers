# Button deboucing

```c
int main (void)
{
	rcc_init();
	gpio_init();
	timer_init();

	/* Toggle Button */
	GPIOA->BSRR = (3UL << 9U);

	uint32_t led_state = 0U;

	while (1)
	{
		if ((GPIOA->IDR & (1UL << 0U)) == 0)
		{	
			delay_ms(20);

			if ((GPIOA->IDR & (1UL << 0U)) == 0)
			{
				led_state ^= 1;
				if (led_state == 1)
				{	
					/* Led on - I/O = 00 */
					GPIOA->BRR = (3UL << 9U);
				}

				else
				{
					/* Led off - I/O == 11 */
					GPIOA->BSRR = (3UL << 9);
				}

				/* Button debouncing */
				while ((GPIOA->IDR & (1UL << 0U)) == 0)
				{
				}
				delay_ms(20);
			}
			
		}
		
	}
}

```