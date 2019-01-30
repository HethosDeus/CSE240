#include<stdio.h>

int init_arrayP(int array[], int size){ //this initializes the array using pointers to the array/size values
   
    int even = 0; int odd = 1; int *i;
    
    for (i = array; *i ; i++){
        
        if (even < *i){
            array[even] = 0;
            even +=2;
        }
        if (odd < *i){
            array[odd] = 1;
            odd += 2;
        }
    }
}

int init_arrayS(int array[], int size){ //this initializes the array 
   
    int even = 0; int odd = 1;
   
    for (int i = 0; i < size; i++){
        
        if (even < size){
            array[even] = 0;
            even +=2;
        }
        if (odd < size){
            array[odd] = 1;
            odd += 2;
        }
    }
}
