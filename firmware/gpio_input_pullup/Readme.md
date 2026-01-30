1. Enable Clock to Port A and C
2. Set PC13 as Input Mode and Enable Pullup for PC13
3. Set PA5 as output for LED toggle output
4. Button is Active Low so we flip the conditional statement using "!" meaning GPIOC->IDR & GPIO_IDR_ID13 should be 0