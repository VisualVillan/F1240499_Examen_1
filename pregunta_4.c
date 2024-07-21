#include <stdint.h>
#include <stdio.h>

void _delay_ms(uint32_t seg){
    for(uint32_t i = 0; i < seg*100000; i++);
}

int main(){
    //GPIO_C (Base) = 0x4001 1000
    //GPIO_CRH (OFFSET)= 0x04
    //GPIO_ODR (OFFSET) = 0x0C
    //RCCAPB2EN (OFFSET) = 0x4002 1000
    //RCCAPB2EN (OFFSET) = 0x18
    
    volatile uint32_t* c_pin = (volatile uint32_t*) 0x40011004;
    volatile uint32_t* c_odr_pin13 = (volatile uint32_t*) 0x4001100C;
    volatile uint32_t* c_odr_pin14 = (volatile uint32_t*) 0x4001100C;
    volatile uint32_t* c_odr_pin15 = (volatile uint32_t*) 0x4001100C;
    volatile uint32_t* c_clock = (volatile uint32_t*) 0x40021018;   

    printf("El valor es: %p \n", c_pin);

    *c_pin &= 0xFF0FFFFF;
    *c_pin |= 0x00200000; // output push-pull y Output mode, max speed 2 MHz

    *c_odr_pin13 |= 0x00002000; // Port output 13
    *c_odr_pin14 |= (1<<14); // Port output 14
    *c_odr_pin15 |= (1<<15); // Port output 15
    
    *c_clock |= (1<<4); //Clock en pinC

    while(1){
        for(int i = 0; i < 20; i++){
            *c_odr_pin13;  //Luz Roja encendida
            _delay_ms(6);
            *c_odr_pin13 &= 0xFFFFDFFF;
            _delay_ms(1);

            *c_odr_pin14;
            _delay_ms(2);
            *c_odr_pin14 &= 0x00000000;
            _delay_ms(1);

            *c_odr_pin15;
            _delay_ms(10);
            *c_odr_pin15 &= 0x00000000;
            _delay_ms(1);
        }
    }
 

    return 0;
}