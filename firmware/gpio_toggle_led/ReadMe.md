## GPIO Toggle LED – Register Level

Target: STM32F446RE (Nucleo)

Purpose:
- Configure GPIOA PA5 using CMSIS register access
- No HAL usage
- Demonstrate MODER, OSPEEDR, and BSRR

Tooling:
- STM32CubeIDE used only for startup, linker, and CMSIS headers
- CubeMX peripheral configuration intentionally unused

Notes:
- Uses reset default clock configuration
- LED toggled via BSRR for atomic set/reset