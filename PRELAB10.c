//KBTHXZ
//PRELAB 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* getPass(char*);//function prototype
int checkPass(char*);//function prototype

int main (int argc, char **argv){
    //argumant count and vector (array of strings)
    if (argc!=2){
        return 0;
    }
    char *fname=argv[1];//only assigns file name!
    char *password= getPass(fname);

    while(checkPass(password)!=1){//error check
        printf("Please re-enter a password 8-12 characters in length, with one capital, one lowercase, one number, and one special character!: \n");
        scanf("%s", password);
    }
    printf("Password %s is valid!\n", password);//valid password
    free (password);

    printf("Freeing memory and exiting!\n");

    return 0;
}//end main

char* getPass(char *fname){
    FILE* fp=fopen(fname, "r");//fp=file pointer
    if(fp==NULL){//safety check for if fopen fails
        return NULL;
    }
    char *password=(char*)malloc(sizeof(char)*12);
    fscanf(fp,"%s",password);//reading line from file

    fclose(fp);//ALWAYS CLOSE THE FILE

    return password;
}//end of getPass

int checkPass(char *password){
    int length=strlen(password);
    int i;
    int hasUpper=0;
    int hasLower=0;
    int hasSpecial=0;
    int hasNum=0;

    if (length<8 || length>12){
        return 0;
    }// checking between 8-12 characters

    for(i=0;i<length;i++){
        if(isupper(*(password+i))!=0){
            hasUpper=1;
        }
        else if(islower(*(password+i))!=0){
            hasLower=1;
        }
        else if(isdigit(*(password+i))!=0){
            hasNum=1;
        }
        else if(ispunct(*(password+i))!=0){
            hasSpecial=1;
        }
    }

    if(hasUpper>0 && hasLower>0 && hasNum>0 && hasSpecial>0){
        return 1;
    }
    else
    {
        return 0;
    } 
}



