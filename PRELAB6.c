//kbthxz
//cs1050

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>


int getInput(void);//prototype
int rngMax(void);//prototype
double initializeArray(int[],int, int);//prototype


int getInput(void){
    int size=0; //initialize array size

    printf("Enter the size of the array to be generated: ");
    scanf("%d", &size);

    while(size<1 || size>99){//error checking 
        printf("Invalid size! Must be between 0 and 100!\n");
        printf("Enter the size of the array to be generated: ");
        scanf("%d", &size);
    }
    return size;
}
int rngMax(void){
    int max=0; //maximum size variable
    printf("Enter the maximum random value to be inserted in the array: ");
    scanf("%d", &max);

    while(max<1 || max>99){
        printf("Invalid number! Enter a maximum random value between 0 and 100: ");
        scanf("%d", &max);
    }
    return max;
}
double initializeArray (int array[],int size, int max){
    int i=0;
    double sum=0;
    for(i=0;i< size; i++){
        array[i]= rand()%max+1;
    }
    for(i=0;i<size;i++){
        sum += array [i];
    }
    return sum;

}
int main (void){
    srand(time(NULL));
    int size= getInput();
    int max=rngMax();
    int array[size];
    double sum=0;
    sum=initializeArray(array,size,max);

    printf("The sum of all the numbers in the array is: %.2lf\n ", sum);
    return 0;
}
