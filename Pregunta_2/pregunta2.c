#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Esta funcion suma los divisores de cada numero menos el mismo numero y los cataloga segun su resultado.
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
    //Creamos una arreglo con 15 elementos.
    srand(time(0));
    int n = 15;
    int array[n];
    //Lazo for con 15 repeticiones para llenar el arreglo con numeros aleatorios.
    //Cada numero aleatorio sea evaluado con la funcion analiza_num.
    for(int i = 0; i < n; i++){
        array[i] = rand()%100;     
        analiza_num(array[i]); 
    }
    return 0;
    
}
