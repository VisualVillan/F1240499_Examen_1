#include <stdint.h>
#include <stdio.h>

// Función para retardar el tiempo en segundos
void _delay_s(uint32_t seg) {
    for(uint32_t i = 0; i < seg*1000000; i++);
}

int main() {
    
    // GPIO_C (Base) = 0x4001 1000
    // GPIO_CRH (OFFSET) = 0x04
    // GPIO_ODR (OFFSET) = 0x0C
    // RCCAPB2EN (Base) = 0x4002 1000
    // RCCAPB2EN (OFFSET) = 0x18
    
    volatile uint32_t* c_pin = (volatile uint32_t*) 0x40011004;
    volatile uint32_t* c_odr = (volatile uint32_t*) 0x4001100C;
    volatile uint32_t* c_clock = (volatile uint32_t*) 0x40021018;

    *c_clock |= (1 << 4); 
    *c_pin &= 0x000FFFFF;
    *c_pin |= 0x22200000; 

    while(1) {
        // Encender luz roja en PC13
        *c_odr |= (1 << 13);
        _delay_s(3);
        *c_odr &= ~(1 << 13); // Apagar luz roja

        // Encender luz amarilla en PC14
        *c_odr |= (1 << 14);
        _delay_s(1);
        *c_odr &= ~(1 << 14); // Apagar luz amarilla

        // Encender luz verde en PC15
        *c_odr |= (1 << 15);
        _delay_s(5);
        *c_odr &= ~(1 << 15); // Apagar luz verde
    }

    return 0;
}
