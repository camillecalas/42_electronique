#include <avr/io.h>

/*
DDRB stands for "Data Direction Register B", and it is a register that controls the direction of the I/O pins in Port B. Each bit of DDRB corresponds to one pin in Port B, and setting the bit to 1 makes the corresponding pin an output pin, while setting the bit to 0 makes the corresponding pin an input pin.

PORTB stands for "Port B Output Register", and it is a register that controls the state of the output pins in Port B. Each bit of PORTB corresponds to one pin in Port B, and setting the bit to 1 makes the corresponding pin high (i.e., set to a logic level of 1), while setting the bit to 0 makes the corresponding pin low (i.e., set to a logic level of 0).

PB0 is a specific pin in Port B, and it can be accessed by setting the appropriate bit in DDRB and PORTB registers. For example, to make PB0 an output pin, you would set the 0th bit of DDRB to 1, and to set PB0 to a logic high level, you would set the 0th bit of PORTB to 1.

In summary, DDRB controls the direction of I/O pins in Port B, PORTB controls the state of the output pins in Port B, and PB0 is a specific pin in Port B that can be controlled by setting the appropriate bits in DDRB and PORTB registers.
*/


/*
Le microcontrôleur utilise des registres pour contrôler les broches d'E/S. Le registre DDRB est un de ces registres, et il est utilisé pour configurer les directions des broches du port B (PB0-PB7). Si le bit correspondant est configuré en sortie, la broche correspondante est une broche de sortie, sinon elle est une broche d'entrée.

Dans l'exemple de code, nous voulons configurer la broche PB0 du port B en sortie. Pour cela, nous utilisons une opération de décalage de bits (1 << PB0) pour obtenir la valeur 1 décalée de PB0 positions, ce qui nous donne la valeur binaire 00000001 avec le bit PB0 mis à 1. Ensuite, nous utilisons l'opérateur OR (|) pour combiner cette valeur avec le registre DDRB. L'opération OR conserve les bits de DDRB qui sont déjà à 1 et met à 1 le bit correspondant à la broche PB0. Enfin, nous stockons le résultat de l'opération OR dans le registre DDRB en utilisant l'opérateur d'affectation |=. Cela configure la broche PB0 du port B en sortie.

|= est un opérateur d'affectation de bits qui combine le registre DDRB avec la valeur 1 décalée de PB0 à l'aide d'une opération OR. Cela signifie que le bit correspondant à la broche PB0 dans le registre DDRB est configuré en sortie (1) sans modifier les autres bits.

En résumé, DDRB |= (1 << PB0) configure la broche PB0 du port B en sortie en configurant le bit correspondant dans le registre DDRB.
*/

int main() 
{
    DDRB |= (1 << PB0);
    
    // Allumer la LED D1
    PORTB = (1 << PB0);

    return 0;
}
