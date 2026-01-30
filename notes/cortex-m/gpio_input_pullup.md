On the nucleo Board the push nutton is connected to PC13 and is externally pullued up via a resistor.

set PC13 as input and enable internal pullup (even if it has external pullups)

Enable PA5 as output to see output in the form of an led toggle



## Common Failure Modes Encountered

- GPIO clock not enabled → registers have no effect
- No main loop → code runs once, no observable behavior
- Incorrect PUPDR encoding → inverted logic
- PC13 on Nucleo is active-low due to external pull-up