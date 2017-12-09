//Katherine Thomas
//kbthxz
//cs1050 Lab4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInput(void);
int menu(void);
int checkPrime(int);
int addDigits(int);
int rngLoop(int);

int main (void){
    int oCount;
    int eCount;
    int total;
    int number; 

    srand(time(NULL));//random number generation

    int input= getInput();//setting return value to input
    while (1)
    {
        int choice= menu();

        switch (choice){

            case 1://Prime number
                number= checkPrime(input);
                if(number==1){
                    printf("%d is a prime number\n",input);
                }
                else{
                    printf("%d is not a prime number\n", input);
                }
                break;

            case 2://sum
                total= addDigits(input);
                printf("The sum of the digits of %d is %d\n",input, total);
                break;

            case 3://Rand values
                eCount= rngLoop(input);
                printf("Even values: %d\n",eCount);
                oCount= input-eCount;
                printf("Odd values Generated: %d\n", oCount);
                break;

            case 4: //exit
                return 0;

            default://error check
                printf("Invalid key!\n");
                printf("Returning to main menu");
                break;
        }
    }
    return 0;
}
int getInput (void){
    int integer=0;
    printf("Please enter an integer between 0 and 1000: ");//prompt
    scanf("%d",&integer);

    while (integer<1 || integer>999){
        printf("Error! Valid numbers are between 1-999!\n");
        printf("Please enter an integer between 0 and 1000: ");
        scanf("%d", &integer);
    }
    return integer;
}

int menu(){
    int choice;
    printf("\n\n***** Main Menu *****\n1)Check Prime Number\n2)Add Up Individual digits\n3)Generate random values\n4)Exit\n....: ");
    scanf("%d", &choice);
    return choice;
}

int checkPrime(int integer){
    int i=0;
    for(i=2;i<=integer/2;++i){
        if( integer%i==0){
            return 0;
        }
    }
    return 1;
}

int addDigits(int integer){
    int total=0;
    int digit=0;
    while (integer!=0){
        digit=integer%10;
        total=total+digit;
        integer/=10;
    }
    return total;
}

int rngLoop(int integer){
    int i, eCount=0;
    for(i=0; i<integer; i++){
        int random= rand()%101;
        printf("%d ", random);

        if (random%2==0){
            eCount++;
        }
    }
    return eCount;
}

