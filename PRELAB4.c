//kbthxz


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInput(void);//defining functions that you're going to use
void rngLoop(int);

int main (void){
    srand(time(NULL)); //random number generation
    //calling getInput Function
    //setting return value into input
    int integer=getInput();
    rngLoop(integer);
    return 0;
}
int getInput(void) {
    int integer=0;

    printf("Please enter an integer between 0 and 100: ");//prompt
    scanf("%d", &integer);

    while (integer<1 || integer>99){
        printf("Error! Valid numbers are from 1-99!\n");
        printf("Please enter an integer between 0 and 100: ");
        scanf("%d", &integer);
    }
    return integer;
}
void rngLoop(int integer){
    int i=0;

    for(i=0; i< integer; i++) {
        int random = rand() % 101;
        printf("%d ", random);
    }

    printf("\n");
    return;
}


