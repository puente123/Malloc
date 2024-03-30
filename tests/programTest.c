#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){

    clock_t start, end;
    double time;
    start = clock();

    printf("Starting Program Testing\n");

    int arraySize = 2000;
    char *array[arraySize];

    for(int i=0; i<arraySize; i++){

        array[i] = (char*)malloc(512); 
    }   

    char *ptr1 = (char*)malloc(4096);

    for(int i=1; i<arraySize; i=i*2){
        free(array[i]);
    }

    free(ptr1);

    char *ptr2 = (char*)malloc(4096);

    char *ptr = (char*)malloc(4);

    free(ptr2);

    char *array2[arraySize];
    for(int j=0; j<arraySize; j++){
        array2[j] = (char*)malloc(16);
    }

    char *ptr3 = (char*)malloc(131072);
    free(ptr3);
    free(ptr);

    for(int j=0; j<arraySize; j++){
        free(array2[j]);
    }

    char *ptr4 = (char*)malloc(4);
    free(ptr4);

    int bigggerArraySize = arraySize *10;
    char *array3[bigggerArraySize];
    for(int j=0; j<bigggerArraySize; j++){
        array3[j] = (char*)malloc(128);
    }
    
    free(array3[bigggerArraySize-1]);
    array3[bigggerArraySize-1] = (char*)malloc(512);

    for(int j=0; j<bigggerArraySize; j++){
        if(j%2 == 0){
            free(array3[j]);
        }
    }

    for(int j=0; j<bigggerArraySize; j++){
        if(j%2 == 0){
            array3[j] = (char*)malloc(4);
        }
    }

    for(int j=0; j<bigggerArraySize; j++){
        if(j%2 != 0){
            free(array3[j]);
        }
    }

    for(int j=0; j<bigggerArraySize; j++){
        if(j%2 != 0){
            array3[j] = (char*)malloc(512);
        }
    }

    end = clock();
    time = (double)(end-start); 
    printf("Time Elapsed: %f\n", (time/CLOCKS_PER_SEC));
  

    return 0;
}