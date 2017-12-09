//Katherine Thomas
//kbthxz
//CS 1050 HW3

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void getCars(int*,float*, int*,char*);
float reserve(int*,float*,int,int);
void printInventory(int*,float*,int*,int);
void writeToFile(int*,float*,int*,char*,int);

int main(int argc, char** argv){
    if (argc !=5){
        printf("Error: Command line! Correct usage: ./a.out <master_input_filename> <number_of_vehicles> <reservation_input_filename> <output_filename>\n");             
        return 0;
    }//end of if
    char* cartxtfile=*(argv+1);//cars.txt
    int carNum=atoi(*(argv+2));//changing it to int & represents size 
    char* reserve1=*(argv+3);//reservationtxt
    char* inventory=*(argv+4);//inventorytxt

    int* carIDs=(int*)malloc(sizeof(int)*carNum);
    float* prices=(float*)malloc(sizeof(float)*carNum);
    int* miles=(int*)malloc(sizeof(int)*carNum);

    int size=0;
    int ID=0;
    float profit=0;
    float check=0;

    getCars(carIDs,prices,miles,cartxtfile);

    printInventory(carIDs,prices,miles,carNum);//print inventory

    FILE* fp=fopen(reserve1,"r");
    if(fp==NULL){
        printf("Reservation file did not open correctly!\n");
        return 0;
    }//end of if

    while(fscanf(fp,"%d", &ID)!=EOF){//ID is reg. variable so it needs &
        profit+=reserve(carIDs, prices, ID, carNum);
    }//end of while

    printf("Processing reservations ...\n");
    printInventory(carIDs,prices,miles,carNum);//prints inventory

    while(1){
        printf("Enter the vehicle ID for the desired rental (0 to exit): \n");
        scanf("%d",&ID);
        if(ID==0){
            break;
        }//end of if
        check=reserve(carIDs, prices, ID, carNum);//checks to see if IDs match
        if(check==-1){
            printf("That vehicle is not in our inventory.\nRe-enter the vehicle ID (0 to exit): \n");
        }//end of if
        else{
            profit+=check;
            printInventory(carIDs,prices,miles,carNum);
        }//end of else
    }//end of while

    printf("Total profits:$%.2f \n", profit);
    writeToFile(carIDs, prices, miles, inventory,size);


    printf("Writing remaining inventory to inventory.txt....\nFreeing memory and exiting.\nGoodbye!\n");
    fclose(fp);//ALWAYS CLOSE FILE
    free(carIDs);
    free(prices);
    free(miles);

    return 0;
}//end of main

void getCars(int* carIDs,float* prices,int* miles,char* carfile){
    FILE* fp=fopen(carfile,"r");
    if(fp==NULL){ //safety check if file doesn't open
        printf("Cars.txt file did not open correctly!\n");
        return;
    }
    int i=0;
    while(fscanf(fp,"%d %f %d",(carIDs+i),(prices+i),(miles+i))!=EOF){
        i++;
    }
    fclose(fp);//ALWAYS CLOSE FP

}//end of getCars

float reserve(int* carIDs, float* prices, int ID, int size){
    int i=0;
    for(i=0;i<size;i++){
        if(*(carIDs+i)==ID){
            *(carIDs+i)=0;
            return *(prices+i);
        }//end if
    }//end for
    return -1;

}//end of reserve

void printInventory(int* carIDs, float* prices, int* miles, int size){
    int i;
    printf("*** Current Inventory ***\n");
    for(i=0;i<size;i++){
        if(*(carIDs+i)!=0){
            printf("%d\t$%.2f\t%d\n",*(carIDs+i),*(prices+i),*(miles+i));
        }//end of if
    }//end of for
}//end of printInventory

void writeToFile(int* carIDs, float* prices, int* miles, char* outfile, int size){
    FILE* fp=fopen(outfile,"w+");//writing
    if(fp==NULL){//if file doesn't open
        printf("Inventory file did not open correctly!\n");
        return;
    }
    int i;
    for(i=0;i<size;i++){
        if(*(carIDs+i)!=0){
            fprintf(fp,"%d\t$%.2f\t%d\n",*(carIDs+i),*(prices+i),*(miles+i));
        }
    }
    fclose(fp);//ALWAYS CLOSE FILE

}//end of writeToFile
