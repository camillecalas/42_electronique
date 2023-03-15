#include <avr/io.h>

/*
DDRB |= (1 << PORTB1);: This line sets pin PB1 as an output by setting the corresponding bit in the Data Direction Register (DDRB) to 1. The |= operator is used to set the bit without affecting the other bits in DDRB.

TCCR1A |= (1 << COM1A0);: This line sets the "Toggle OC1A on Compare Match" (COM1A0) bit in Timer/Counter Control Register 1A (TCCR1A) to 1. This will cause the output pin (PB1) to toggle its state on every compare match.

TCCR1B |= (1 << WGM12);: This line sets the "Waveform Generation Mode" (WGM) bits in Timer/Counter Control Register 1B (TCCR1B) to 0100, which configures timer 1 for Fast PWM mode with OCR1A as the TOP value.

OCR1A = 31249;: This line sets the Output Compare Register 1A (OCR1A) to a value that will produce a frequency of 1 kHz with a 256 prescaler. The formula for calculating this value is: OCR1A = (F_CPU / (2 * N * f)) - 1, where F_CPU is the CPU frequency, N is the prescaler value, and f is the desired frequency.

TCCR1B |= (1 << CS12);: This line sets the prescaler for timer 1 to 256 by setting the "Clock Select" (CS) bits in TCCR1B to 100. This will cause the timer to count up at a rate of 62.5 kHz (16 MHz / 256).

while (1) {}: This line creates an infinite loop that will keep the program running indefinitely.
*/

int main()
{
    DDRB |= (1 << PORTB1);
    TCCR1A |= (1 << COM1A0);
    TCCR1B |= (1 << WGM12);

    OCR1A = 31249;

    TCCR1B |= (1 << CS12);

    while (1)
    {}

    return (0);
}