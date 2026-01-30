# GPIO Register Configuration – STM32F446

## Reset State
After reset almost al GPIO registers return to 0x0000 0000 except jtag and SWD
PA5 remians a floating pin disconnected from drivers

## Clock Enable (RCC)
Without RCC clock the internal Flip flops and logic gates do not function although code will run the registers will not show output

## MODER
EACh pin requires 2 bits so because there are 4 possible combinations 
00 : Input (default)
01 : General purpose Output
10 : AF (PWM, SPI, UART)
11 : Analog(For ADC, DAC)

## OTYPER
Push PULL : The MCU drives the pin to 3.3V and GND 
Open Drain : The MCU only drive the pin  to gnd, need external pull upsm Used in I2 protocol

## OSPEEDR
Controls slew rate of the the 0 to 3.3V transition directly affects speed and electrical noise is speed is high

## PUPDR
PULl Up : Connects to a weak internal resistor to 3.3V
Pull down : Connects to a weak internal resistor connected to GND

Makes sure randon noise doesnt trigger register state 

## ODR vs BSRR
ODR - to toggle a pin you must read odr, modify that bit, Write it back, if and interrupt happens in the middle of this you  might overwrite a change made my that interupt

BSRR- this is write only register and is atomic meaning hardware handles change in a single step

## Notes
Default clock configuration 16mHz HSI
led Wired to PA5 on nucleo f446
