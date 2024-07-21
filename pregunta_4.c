#include <stdint.h>
#include <stdio.h>

int main(){
    //GPIO_C (Base) = 0x4001 1000
    //GPIO_CRH (OFFSET)= 0x04
    //GPIO_ODR (OFFSET) = 0x0C
    //RCCAPB2EN (OFFSET) = 0x4002 1000
    //RCCAPB2EN (OFFSET) = 0x18
    

    volatile uint32_t* c_pin = (volatile uint32_t*) 0x40011004;
    volatile uint32_t* c_odr = (volatile uint32_t*) 0x4001100C;
    volatile uint32_t* c_clock = (volatile uint32_t*) 0x40021018;   

    printf("El valor es: %p \n", c_pin);

    *c_pin &= 0xFF0FFFFF;
    *c_pin |= 0x00200000; // output push-pull y Output mode, max speed 2 MHz
    *c_odr |= 0x00002000; // Port output 13
    *c_clock |= (1<<4); //Clock en pinC

    while(1){
        *c_odr |= 0x00002000;
        __delay_ms(10);
        *c_odr &= 0xFFFFDFFF;
        __delay_ms(10);
    }
 

    return 0;
}