//katherine thomas
//kbthxz
//cs1050

#include <stdio.h>

int getInput(void); //function prototype
int getLength(char[]);//function prototype

int main (){
    int size;//size of array
    int length;// length of character string
    char string1;// reserves number of character space
    size=getInput();//calling getinput

    printf("Enter a string: \n");
    scanf("%c", &string1);

    char array[size]=string1;

    length=getLength(array);

    printf("The length of %c is %d. ", string1, length);

    return 0;
}
int getInput(void){
    int size=0;//intialize variable
    printf("Enter a length for the character array: ");
    scanf("%d", &size);

    return size;
}
int getLength(char array[]){
    int length;
    int i;

    for (i=0;array[i]!='\0'; i++){
        length++;
    }
    return length;
}
