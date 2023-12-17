#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 500

int main() {
    DDRB |= (1 << DDB5);
    while(1){
      PORTB |= (1 << PB2);
      _delay_ms(BLINK_DELAY_MS);
      PORTB &= ~(1 << PB2);
      _delay_ms(BLINK_DELAY_MS);
    }

    return 0;
}