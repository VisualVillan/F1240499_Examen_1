#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void analiza_num(int a){
    //printf("El numero es: %i \n", a);
    int suma = 0;
    for(int i = 1; i < a; i++){        
        if(a % i == 0){
            int divisor = i; 
            suma += divisor;
            //printf("%i es divisor\n", divisor);
        }else{}   
    }
    //printf("%i es la suma de los divisores\n", suma);
    if(suma < a){
        printf("%i - Deficiente\n", a);
    }else if(suma == a){
        printf("%i - Perfecto\n", a);
    }else{printf("%i - Abundante\n", a);}
    
}


int main(){

    srand(time(0));
    int n = 15;
    int array[n];
    
    for(int i = 0; i < n; i++){
        array[i] = rand()%100;     
        analiza_num(array[i]); 
    }
    return 0;
    
}
