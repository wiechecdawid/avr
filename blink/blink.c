#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 500

int main() {
    DDRB |= (1 << DDB5);
    while(1){
      PORTB ^= _BV(PB2);
    }

    return 0;
}