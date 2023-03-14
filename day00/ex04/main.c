#include <avr/io.h>
#include <util/delay.h>

/*
PD2 is a bit position in the registers DDRD, PORTD, and PIND that correspond to a specific physical pin on the AVR microcontroller. In other words, PD2 represents the specific pin on Port D that you are interested in controlling or reading.

PIND, on the other hand, is a register that is used to read the state of the pins on Port D. The value of PIND reflects the current state of the input pins on Port D at the time the register is read. For example, if you want to read the state of the pin corresponding to PD2 on Port D, you can use the expression PIND & (1 << PD2) to read the value of PIND and check whether the bit corresponding to PD2 is set or not.
*/

/*
1 << PD2 décale un 1-bit vers la gauche de PD2 positions, de sorte que le bit correspondant à PD2 est mis à 1 et tous les autres bits sont mis à 0. Par exemple, si PD2 vaut 2, 1 << PD2 sera égal à 0b00000100.
(PIND & (1 << PD2)) effectue un ET logique entre le registre PIND (qui contient l'état de toutes les broches de port D) et la valeur de 1 << PD2. Cela a pour effet de conserver uniquement le bit correspondant à PD2 et de mettre tous les autres bits à 0. Si la broche PD2 est à l'état logique bas (c'est-à-dire si elle est connectée à la terre), le résultat sera égal à 0, sinon le résultat sera différent de 0.
Enfin, != 0 vérifie si le résultat de l'opération précédente est différent de zéro, ce qui signifie que la broche PD2 est à l'état logique bas. Si la broche est à l'état logique haut, le résultat sera égal à zéro, ce qui correspond à la valeur booléenne false en langage C. Si la broche est à l'état logique bas, le résultat sera différent de zéro, ce qui correspond à la valeur booléenne true en langage C.
*/

#define ON 1
#define OFF 0

int main() 
{
    // mettre en mode sortie
    DDRB |= (1 << PB0);
    // mettre en mode entree
    DDRD |= (0 << PD2);

    //Activer la resistance de pull-up pour PD2
    PORTD |= (1 << PD2);

    int button_state = OFF;
    int led_state = OFF;
    
    while (1)
    {
        // Button is pressed and was previously not pressed
        /*
        Dans ce cas, si le troisième bit de PIND est défini, cela signifie que la broche D2 est haute et le code à l'intérieur du bloc if sera exécuté. Si le troisième bit de PIND n'est pas défini, cela signifie que la broche D2 est basse et le code à l'intérieur du bloc else sera exécuté.
        */
        if ((PIND & (1 << PD2)) != 0 && button_state == OFF)
        {
            led_state = !led_state;
            if (led_state == ON)
            {
                // Allumer la LED D1
                PORTB |= (1 << PB0);
            }
            else
            {
                // Eteindre la LED D1
                PORTB &= ~(1 << PB0);
            }
            button_state = ON;
        }
        else if ((PIND & (1 << PD2)) == 0 && button_state == ON )
        {
            button_state = OFF;
        }
    }
    return 0;
}
