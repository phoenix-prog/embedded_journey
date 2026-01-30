#include "stm32f446xx.h"

#define GPIO_MODE_OUTPUT 0x1U

void delay(volatile uint32_t count) {
    while(count--) {
        __NOP();
    }
}

int main(void) {
    // 1. Enable Clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // 2. Configure PA5
    GPIOA->MODER &= ~(GPIO_MODER_MODER5_Msk);//Clear PA5 MODER bits
    GPIOA->MODER |= (GPIO_MODE_OUTPUT << GPIO_MODER_MODER5_Pos);// SET PA5 to OUTPUT

    // 3. Fix the OSPEEDR naming error
    GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED5_Msk); // CLEAR OSPEEDR PA5 bits this sets to low speed
    while (1) {
        GPIOA->BSRR = GPIO_BSRR_BS5; // Set High
        delay(500000);
        GPIOA->BSRR = GPIO_BSRR_BR5; // Reset Low
        delay(500000);
    }
}
