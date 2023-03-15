#include <avr/io.h>

/*
Tout d'abord, on configure la broche PB1 comme une sortie en définissant le bit correspondant de DDRB.
Ensuite, on configure le Timer1 en mode PWM avec une fréquence de 62500 Hz en modifiant les registres TCCR1A, TCCR1B et OCR1A. Pour obtenir un rapport cyclique de 10%, on active le bit COM1A1 dans le registre TCCR1A. Ce bit indique que la broche OC1A (correspondant à la broche PB1) doit être mise à l'état haut lorsque le compteur atteint la valeur OCR1A. Le bit WGM10 dans le registre TCCR1A est également activé pour sélectionner le mode de comptage PWM à 8 bits. Ensuite, on configure le prescaler à 256 en activant le bit CS12 dans le registre TCCR1B. Enfin, on assigne la valeur 1562 au registre OCR1A pour obtenir un rapport cyclique de 10% avec une fréquence de 62500 Hz.
Enfin, on entre dans une boucle infinie pour maintenir le microcontrôleur en fonctionnement.
*/

int main()
{
    DDRB |= (1 << PORTB1);
    TCCR1A |= (1 << COM1A1) | (1 << WGM10);
    TCCR1B |= (1 << WGM12) | (1 << CS12);

    OCR1A = 1562;

    while (1)
    {}

    return (0);
}
