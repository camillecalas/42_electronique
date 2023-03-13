#include <avr/io.h>
#include "stdio.h"

/*
Le microcontrôleur utilise des registres pour contrôler les broches d'E/S. Le registre DDRB est un de ces registres, et il est utilisé pour configurer les directions des broches du port B (PB0-PB7). Si le bit correspondant est configuré en sortie, la broche correspondante est une broche de sortie, sinon elle est une broche d'entrée.

Dans l'exemple de code, nous voulons configurer la broche PB0 du port B en sortie. Pour cela, nous utilisons une opération de décalage de bits (1 << PB0) pour obtenir la valeur 1 décalée de PB0 positions, ce qui nous donne la valeur binaire 00000001 avec le bit PB0 mis à 1. Ensuite, nous utilisons l'opérateur OR (|) pour combiner cette valeur avec le registre DDRB. L'opération OR conserve les bits de DDRB qui sont déjà à 1 et met à 1 le bit correspondant à la broche PB0. Enfin, nous stockons le résultat de l'opération OR dans le registre DDRB en utilisant l'opérateur d'affectation |=. Cela configure la broche PB0 du port B en sortie.

|= est un opérateur d'affectation de bits qui combine le registre DDRB avec la valeur 1 décalée de PB0 à l'aide d'une opération OR. Cela signifie que le bit correspondant à la broche PB0 dans le registre DDRB est configuré en sortie (1) sans modifier les autres bits.

En résumé, DDRB |= (1 << PB0) configure la broche PB0 du port B en sortie en configurant le bit correspondant dans le registre DDRB.
*/

/*
    ^ = XOR opearator : the result will be 1 if only one of the bits is 1. If both bits are 0 or both are 1, the result will be 0.
*/

/*
PORTB ^= (1 << PB0) is a line of code in C or C++ programming language. Here is what it does:

PORTB is a register in a microcontroller that controls the state (high or low voltage) of the pins in the B port. Each bit of the register corresponds to a pin, so PORTB is an 8-bit register.
PB0 is a constant defined in the code that represents the first bit (or pin) of the B port.
<< is the left shift operator that shifts the binary value 1 to the left by the number of positions specified by PB0. In this case, PB0 is 0, so (1 << PB0) is simply 1.
^ is the bitwise XOR operator that performs a bitwise exclusive OR operation between the value of PORTB and the value of (1 << PB0). This means that for each bit in PORTB and the corresponding bit in (1 << PB0), the result will be 1 if only one of the bits is 1. If both bits are 0 or both are 1, the result will be 0.
Finally, the result of the XOR operation is written back to PORTB, effectively toggling the state of the first pin of the B port.
In summary, the line of code PORTB ^= (1 << PB0) toggles the state of the first pin of the B port of a microcontroller by performing a bitwise XOR operation between the current state of the B port and the value 1 shifted left by 0 bits.
*/


// 12500 x le temps d'attente d'une instruction est d'environ 500 ms

int main() 
{
    DDRB |= (1 << PIN0);

    // Boucle infinie
    while (1)
    {
        // Dans la boucle infinie, nous alternons l'état de la LED D1 en utilisant l'opération bitwise XOR (^) avec la valeur 1 décalée de PB0 (1 << PB0).
        PORTB ^= (1 << PIN0);

        // Attendre 500ms
        for (long i = 0; i < 12500; i++);
    }

    return 0;
}
