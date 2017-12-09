//Katherine Thomas
//kbthxz   
//CS1050 Lab8

#include <stdio.h>

float* addValues (float*, int);//function prototype
float* sort(float*,int);//function prototype
void calculations(float*,int);//function prototype

int main (){
    int num=0;//declare & intialize variable
    float *a1Ptr;//declare pointer

    printf("Please enter the number of values you wish to input: \n");
    scanf("%d", &num);
    while( num<1){//error checking num to be pos.
        printf("Number of values must be a positive integer! Try again: \n");
        scanf("%d", &num);
    }
    float myArray[num];//declare array
    a1Ptr=myArray;//pointer set to array

    a1Ptr=addValues(a1Ptr,num);//sending pointer & input to addValues
    a1Ptr=sort(a1Ptr,num);//sending pointer & input to sort
    calculations(a1Ptr,num);//calculations recieves pointer & input

    return 0;
}

float* addValues(float*a1Ptr,int num){
    int i;//declare counter

    for(i=0;i<num;i++){
        printf("Enter a value: \n");
        scanf("%f", a1Ptr+i);
    }

    return a1Ptr;//returns pointer
}

float* sort(float*a1Ptr,int num){
    int pass;
    int i;
    float hold;

    for(pass=1;pass<num;++pass){//bubble sort for descending order
        for(i=0;i<num-1;i++){
            if(*(a1Ptr+i)<*(a1Ptr+i+1)){
                hold=*(a1Ptr+i);
                *(a1Ptr+i)=*(a1Ptr+i+1);
                *(a1Ptr+i+1)=hold;
            }
        }
    }
    printf("Sorted values in descending order: \n");
    for(i=0;i<num;++i){
        printf("%.2f ",*(a1Ptr+i));
    }

    return a1Ptr;//returns pointer 
}
void calculations(float*a1Ptr,int num){
    int i;
    float total=0;
    float mean=0;
    float median=0;
    float range=0;

    for(i=0;i<num;i++){//mean
        total+=*(a1Ptr+i);
    }
    mean=(total/num); //calculating mean
    printf("\nMean of the data set: %lf.\n", mean);


    if(num%2==0){
        median=(*(a1Ptr+num/2)+*((a1Ptr+num/2)-1))/2;
        printf("Median of the data set: %lf. \n", median);

    }
    else{     
        median=*(a1Ptr+num/2);
        printf("Median of the data set: %lf.\n", median);
    }

    range=*(a1Ptr+0)-*(a1Ptr+num-1);//calculating range
    printf("Range of the data set: %lf.\n ",range);
}


