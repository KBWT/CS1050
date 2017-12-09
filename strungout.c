//Katherine Thomas
//kbthxz
//CS 1050 Lab7

#include <stdio.h>
#define MAX 25

int length(char[]); //function prototype
int replace(char[],int);//function prototype
void concatenate(char[],char[]);//function prototype
void sort(char[]);//function prototype

int main(){
    char string1[MAX];
    char string2[MAX];
    int Length=0;
    int position=0;
    int fred=0;



    printf("Enter the first string: \n");
    scanf("%s", string1);
    printf("First string is: %s \n", string1);

    Length=length(string1);//calling length function
    printf("Length of the first string is: %d \n", Length);

    printf("Enter a position for the replacement operation between 1-%d: \n", Length);
    scanf("%d",&position);

    fred=replace(string1, position);

    //calling replace function
    while (fred !=1){
        printf("Invalid position! Enter a position between 1-%d: ",Length);
        scanf("%d", &position);

        fred=replace(string1, position);
    }
    printf("The first string after the replacement operator is: %s \n", string1);

    printf("Enter the second string: \n");
    scanf("%s", string2);

    concatenate(string1, string2);//calling concatenate function
    printf("The first string after concatenation with the second is: %s\n", string1);

    printf("First string before sorting: %s\n",string1);

    sort(string1);//calling sort function
    printf("\nFirst string after sorting:%s",string1);

    return 0;
}

int length(char string1[]){
    int length=0;//inititalizing length
    int i;

    for (i=0;string1[i]!='\0';i++){
        length++;
    }
    return length;
}

int replace(char string1[], int position){
    int sue=0;
    sue= length(string1);

    if (sue < position || position < 1){
        return 0;
    }
    else{

        string1[position - 1]='#';
        return 1;
    }
}

void concatenate(char string1[], char string2[]){
    int i=0;
    int j;
    i=length(string1);

    for (j=0;string2[j]!='\0';++j,++i){
        string1[i]=string2[j];
    }
    string1[i]='\0';
}

void sort(char string1[]){
    int i=0;
    int j=0;
    int hold=0;
    int Length=0;

    Length=length(string1);

    for(i=0;i<Length;j++){
        for(j=0;j< Length-1;j++){
            if (string1[j]> string1[j+1]){
                hold=string1[j];
                string1[j]=string1[j+1];
                string1[j+1]=hold;
            }
        }
    }
}


