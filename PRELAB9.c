//Katherine Thomas
//PreLab9

#include <stdio.h>

void deposit(int *, float *, int);//prototype
void summary(int *, float *, int);//prototype

int main(){
    int account;//number of accounts variable
    int *ptr_pin;//pointer
    float *ptr_bal;//pointer

    printf("How many accounts are to be created?: \n");
    scanf("%d", &account);
    while( account<1)
    {//error checking positive number
        printf("Number of accounts must be positive number! Re-enter desired number of accounts: \n");
        scanf("%d", &account);
    }

    ptr_pin=malloc(sizeof(*ptr_pin));
    ptr_bal=malloc(sizeof(*ptr_bal));




