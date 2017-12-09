//Katherine Thomas
//kbthxz
//CS1050 Prelab 8

#include <stdio.h>
#include <stdlib.h>
#define MAX 15
char* getInput();
char* changeString(char*);

int main(){

    char* s1Ptr = getInput();

    printf("String %s is stored at memory address %p.\n", s1Ptr, &s1Ptr);

    s1Ptr=changeString(s1Ptr);
    printf("String %s is stored at memory address %p.\n", s1Ptr, &s1Ptr);

    return 0;
}

char* getInput(){

    char string1[MAX];//define string1 array
    char *s1Ptr;// s1Ptr is pointer to char string1

    printf("Please enter a character string: \n");
    scanf("%s", string1);
    s1Ptr=string1;//pointer set to array

    return s1Ptr;
}

char* changeString(char* s1Ptr){

    char string2[MAX];//define string2 array

    printf("Please enter a new replacement string: \n");
    scanf("%s", string2);

    s1Ptr=string2;//pointer set to array

    return s1Ptr;
}






