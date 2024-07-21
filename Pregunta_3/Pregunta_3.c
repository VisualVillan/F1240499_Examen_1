#include <stdio.h>

int main(){
    // BASE GPIO_PORT0 = 0x50000000
    // OFFSET OUT = 0x504 
    // OFFSET OUTSET = 0x508 
    // OFFSET OUTCLR = 0x50C 
    // OFFSET IN = 0x510
    // OFFSET DIR = 0x514
    // OFFSET DIRSET = 0x518
    // OFFSET DIRCLR = 0x51C

    volatile uint32_t* OUT = (volatile uint32_t *) 0x50000504;
    volatile uint32_t* OUTSET = (volatile uint32_t *) 0x50000508;
    volatile uint32_t* OUTCLR = (volatile uint32_t *) 0x5000050C;
    volatile uint32_t* IN = (volatile uint32_t *) 0x50000510;
    volatile uint32_t* DIR = (volatile uint32_t *) 0x50000514;
    volatile uint32_t* DIRSET = (volatile uint32_t *) 0x50000518;
    volatile uint32_t* DIRCLR = (volatile uint32_t *) 0x5000051C;

}
