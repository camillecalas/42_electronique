#include <avr/io.h>
#include <util/delay.h>

/*
PORTB = (PORTB & 0b11110000) | (value & 0b00001111);

Le masque binaire est utilisé pour ne prendre en compte que les 4 bits les moins significatifs de la variable "value" lors de l'affichage sur les LEDs.

Le masque binaire est composé de deux parties :

Le premier masque (0b11110000) est utilisé pour préserver les 4 bits les plus significatifs de la valeur actuelle de PORTB (les bits 4 à 7). Pour ce faire, on utilise l'opérateur binaire ET (&) qui permet de conserver les bits 4 à 7 de PORTB tout en mettant à zéro les bits 0 à 3.

Le deuxième masque (0b00001111) est utilisé pour ne prendre en compte que les 4 bits les moins significatifs de la variable "value". Pour ce faire, on utilise à nouveau l'opérateur binaire ET (&) qui permet de ne conserver que les bits 0 à 3 de "value" tout en mettant à zéro les bits 4 à 7.

Ensuite, les deux parties du masque sont combinées à l'aide de l'opérateur binaire OU (|) pour obtenir la valeur à écrire sur le port B. Cette opération permet de copier les 4 bits les plus significatifs de la valeur actuelle de PORTB et de les combiner avec les 4 bits les moins significatifs de la variable "value".
*/

int main(void) 
{
    // mettre en mode sortie
    DDRB |= (1 << PB0);
    DDRB |= (1 << PB1);
    DDRB |= (1 << PB2);

    DDRB |= (0 << PB3);
    DDRB |= (1 << PB4);

   


    // Initialisation des variables
    uint8_t value = 0b00000000; // Valeur à afficher sur les LEDs

    while (1) 
    {
       
        value = (1 << value);
        // Petite temporisation pour éviter les rebonds
        _delay_ms(300); 

        // Affichage de la valeur sur les LEDs seuls les bits 0 a 7 sont conserves pr PORTB et seuls les bits 0 a 3 sont conserves pour VALUE
        PORTB = (PORTB & 0b11101000) | (value & 0b00010111);
    }

    return 0;

}
