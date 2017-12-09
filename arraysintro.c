//Katherine Thomas
//kbthxz
//CS 1050 Lab6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInput(void);//prototype
int rngMax(void);//prototype
void initializeArray(int,int);//prototype
int arrayMin(int[], int);//prototype
int arrayMax(int[],int);//prototype
double arrayAvg(int[],int);//prototype

int main (void){
    // srand(time(NULL)) random values
    int size=getInput();
    int max=rngMax();
    initializeArray(size, max);//sends size and max to prototype
    return 0;
}
int getInput(void){
    int size=0;//initialize array size

    printf("Enter the size of the array to be generated: ");
    scanf("%d", &size);

    while (size<1 || size>99){ //error checking
        printf("Invalid size! Must be between 0 and 100.\n  Enter the size of the array to be generated: ");
        scanf("%d", &size);
    }
    return size;
}
int rngMax(void){
    int max=0;//initialize max variable 
    printf("Enter the maximum random value to be inserted in the array: ");
    scanf("%d",&max);

    while(max<1||max>99){ //error checking
        printf("Invalid number! Enter a maximum random value between 0 and 100: \n");
        scanf("%d", &max);
    }
    return max;
}
void initializeArray(int size, int max){
    int i=0;//initialize i 
    int array[size];
    srand(time(NULL));
    for(i=0;i<size;i++){
        array[i]=rand()%max+1;
    }
    int min=arrayMin(array,size);
    int maximum=arrayMax(array,size);
    double average=arrayAvg(array,size);

    printf("The minimum value is %d and occurs at index %d\n", array[min],min);
    printf("The maximum value is %d and occurs at index %d\n", array[maximum],maximum);
    printf("The mean of the data is %.2lf\n",average);
}
int arrayMin(int array[],int size){//finding min of random array
    int i=1;
    int index=0;
    int min=array[0];
    for(i=1;i<size;i++){
        if (array[i]<=min){
            min=array[i];
            index=i;
        }
    }
    return index;       
}
int arrayMax(int array[],int size){//finding max of random array
    int i=1;
    int index=0;

    int  maximum=array[0];
    for (i=1; i<size; i++){
        if (array[i]>=maximum){
            maximum=array[i];
            index=i;
        }
    }
    return index;
}

double arrayAvg(int array[],int size){//finding average of random array
    double average=0;
    double sum=0;
    int i=0;

    for(i=0; i<size; i++){
        sum+=array[i];
    }
    average=sum/(double)size;


    return average;
}





















































