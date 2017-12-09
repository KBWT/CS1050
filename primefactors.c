// Katherine Thomas
// kbthxz
// CS1050 Lab 3
#include <stdio.h>

int main ( void ){
    int integer;
    int a;
    int b;
    int i;
    int menu;

    printf("Enter a number between 0 and 100: ");//asks for user input
    scanf ("%d", &integer);//scans number

    while (0>=integer || 100<=integer){
        printf("That number is outside the acceptable range!\n");//warning

        printf("Enter a number between 0 and 100: ");
        scanf("%d", &integer);
    }
    while((menu !=0)){
        printf( "Select an option number from the following choices.\n"); 

        printf("1) List all prime numbers.\n");
        printf("2) Factorize the integer.\n");
        printf("0) Exit\n" );
        scanf( "%d", &menu);//reads menu option

        switch(menu){

            case 1://prime numbers
                for(a=2; a<=integer;a++){
                    int prime=1;
                    for(b=2;b<a;b++){
                        if(a%b==0){
                            prime=0;
                            break;
                        }
                    }

                    if(prime==0 && integer!=1){
                        printf("%d ", a);
                    }
                }
                break;

            case 2://factorize the integer
                for(i=1;i<=integer;i++){
                    if(integer%i==0){
                        printf("%d ",i);
                    }
                }
                break;

            case 0: //exit
                printf("You have exited the program\n");
                return 0;

            default: //invalid entry
                printf(" Invalid entry! Returning to menu..\n");
                break;
        }
    }
    return 0;
}


