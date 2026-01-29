#include "stm32f446xx.h"

void delay(volatile uint32_t count) {
    while(count--) {
        __NOP();
    }
}

int main(void) {
    // 1. Enable Clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // 2. Configure PA5
    GPIOA->MODER &= ~(GPIO_MODER_MODER5_Msk);
    GPIOA->MODER |= (1 << GPIO_MODER_MODER5_Pos);

    // 3. Fix the OSPEEDR naming error
    GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED5_Msk); // Removed the extra 'R'

    while (1) {
        GPIOA->BSRR = GPIO_BSRR_BS5; // Set High
        delay(500000);
        GPIOA->BSRR = GPIO_BSRR_BR5; // Reset Low
        delay(500000);
    }
}
