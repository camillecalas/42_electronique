#include <avr/io.h>
#include <util/delay.h>

/*
PD2 is a bit position in the registers DDRD, PORTD, and PIND that correspond to a specific physical pin on the AVR microcontroller. In other words, PD2 represents the specific pin on Port D that you are interested in controlling or reading.

PIND, on the other hand, is a register that is used to read the state of the pins on Port D. The value of PIND reflects the current state of the input pins on Port D at the time the register is read. For example, if you want to read the state of the pin corresponding to PD2 on Port D, you can use the expression PIND & (1 << PD2) to read the value of PIND and check whether the bit corresponding to PD2 is set or not.
*/


int main() 
{
    DDRB |= (1 << PB0);
    // mettre en mode entree
    DDRD |= (0 << PD2);
    
    //Activer la resistance de pull-up pour PD2
    PORTD |= (1 << PD2);
    
    while (1)
    {
        if (!(PIND & (1 << PD2)))
        {
            // Allumer la LED D1
            PORTB |= (1 << PB0);
        }
        else
        {
            // If the result of the expression PIND & (1 << PD2) is not 0, that means the PD2 pin is high (i.e. the pushbutton is not being pressed), so the code sets the output state of the PB0 pin on Port B to low by writing a 0 to the corresponding bit in the PORTB register using the expression PORTB &= ~(1 << PB0).
            PORTB &= ~(1 << PB0);
        }
    }



    return 0;
}
