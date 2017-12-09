//Kbthxz
//Katherine Thomas
//CS1050 Lab 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getPass(char*, char*);//function prototype
int checkPass(char*);//function prototype

int main(int argc, char **argv){
    if (argc!=3){
        printf("Command line argument error!\n Correct usage './a.out <input_filename> <output_filename>\n");
        return 0;
    }// at least three arguments on command line

    char* input=*(argv+1);
    char* output=*(argv+2);
    int total=0;
    total=getPass(input,output);

    if(total==-1){
        printf("Error in opening the files!\n");
    }

    printf("There were %d valid passwords written to %s\n", total, output);


    printf("Freeing memory and exiting..\n\n");
    return 0;
}//end of main

int getPass(char* input, char* output){
    FILE* fp=fopen(input,"r");
    FILE* fp2=fopen(output,"w");
    if (fp==NULL){//saftey check if fopen fails
        printf("Incomplete..");
        return -1;
    }
    if (fp2==NULL){
        printf("Incomplete..");
        return -1;
    }

    char *password=(char*)malloc(sizeof(char)*20);
    int counter=0;

    while(fscanf(fp,"%s", password)!=EOF){

        int valid=checkPass(output);
        if(valid==1){
            fprintf(fp2,"%s\n",password);
            counter++;
        }
    }
    fclose(fp);//ALWAYS CLOSE THE FILE 
    fclose(fp2);

    free(password);
    return counter;//returns the number of valid passwords to main

}//end of get pass function

int checkPass(char* password){
    int length=strlen(password);
    int i;
    int hasUpper=0;//uppercase
    int hasLower=0;//lowercase
    int hasNum=0;//number
    int hasSpecial=0;//special character

    if(length<8 || length>12) {
        return 0;
    }//checking between 8-12 characters in the password

    for(i=0;i<length;i++){
        if (isupper(*(password+i))){
            hasUpper=1;
        }
        if (islower(*(password+i))){
            hasLower=1;
        }
        if (isdigit(*(password+i))){
            hasNum=1;
        }
        if (ispunct(*(password+i))){
            hasSpecial=1;
        }
    }
    if(hasUpper>0 && hasLower>0 && hasNum>0 && hasSpecial>0){
        return 1;
    }
    else{
        return 0;
    } 


}//end on check pass function
