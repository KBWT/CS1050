//katherine thomas
//cs1050
//prelab 3

#include <stdio.h>

int main ( void ) {
    int number; //variable for users number
    int counter; //define counter

    printf( "Enter a number between 1 and 99: ");
    scanf( "%d", &number);

    while (0>=number || 100<=number ){
        printf(" Invalid number! Re-enter a valid integer between 1-99: ");
        scanf( "%d \n", &number);
    }
    for (counter=1; counter <=number;counter++) {
        printf( "%d \n", counter);
    }

    switch (number%2){
        case 0:
            printf( "The integer is even. \n" );
            break;

        default:
            printf( "The integer is odd.\n" );
            break;
    }	

    return 0;
}


