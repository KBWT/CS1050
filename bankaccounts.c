//Katherine Thomas
//kbthxz
//CS1050 Lab 9

#include <stdlib.h>
#include <stdio.h>

int menu(void);//prototype
void createAccounts(int*,float*,int);//prototype
int deposit(int*, float*,int);//prototype
int withdraw(int*,float*,int);//prototype
void summary(int*,float*,int);//prototype

int main(){
    int account;//number of accounts variable

    int put_in;//deposit variable
    int take_out;//withdrawal variable

    printf("How many accounts are to be created?: \n");
    scanf("%d",&account);
    while(account<1)
    {//error checking for positive num
        printf("Number of accounts must be positive number and greater than 1! Re-enter the number of accounts: \n");
        scanf("%d", &account);
    }

    int *ptr_pin=malloc(sizeof(int)*account);
    float *ptr_bal=malloc(sizeof(float)*account);

    createAccounts(ptr_pin,ptr_bal,account);//sending pointers and accounts to function

    while(1) 
    {
        int choice=menu();
        switch(choice){
            case 1://deposit function
                put_in=deposit(ptr_pin, ptr_bal, account);//calling deposit function
                if(put_in==1)
                {
                    printf("Deposit successful!\n");
                }
                else
                {
                    printf("Deposit Error!Please try again! Verify Account PIN?\n");
                }
                break;

            case 2://withdraw function
                take_out=withdraw(ptr_pin,ptr_bal,account);//calling withdraw function
                if(take_out==1)
                {
                    printf("Withdawal successful!\n");
                }
                else
                {
                    printf("Withdrawal unsuccessful. Please try again!\n");
                }
                break;
            case 3://summary
                summary(ptr_pin,ptr_bal,account);//calling summary function
                break;
            case 4://Exit
                summary(ptr_pin,ptr_bal,account);//calling summary function
                return 0;
                break;
            default:
                printf("Invalid menu choice!\nReturning to main menu...\n");
                break;
        }
    }

    return 0;
}
int menu(){
    int choice=0;
    printf("\n\n*** MENU ***\n1)Deposit Funds\n2)Withdraw Funds\n3)Print active account summary\n4)Exit\n...: \n");
    scanf("%d",&choice);
    return choice;
}
void createAccounts(int*ptr_pin,float*ptr_bal,int account){
    int i;
    int num=1;

    for(i=0;i<account;i++,num++)
    {
        printf("Account #%d PIN: \n",num);
        scanf("%d",(ptr_pin+i));

        printf("Account #%d initial balance: \n",num);
        scanf("%f", (ptr_bal+i));

        while(*(ptr_pin+i)<1000||*(ptr_pin+i)>9999)
        {
            printf("Invalid pin! Must be four digits! Re-enter pin: \n");
            scanf("%d", (ptr_pin+i));
        }
        while(*(ptr_bal+i)<1)
        {
            printf("Initial balance must be greater than $1. Please put in more money: \n");
            scanf("%f", (ptr_bal+i));
        }
    }
}
int deposit(int*ptr_pin, float*ptr_bal, int account){
    float money=0;
    int PIN=0;
    int i;

    printf("Account PIN: \n");
    scanf("%d",&PIN);
    for(i=0;i<account;i++)
    {
        if(PIN != *(ptr_pin+i))
        {
            return 0;//if pin doesnt match
        }
        if(PIN==0||PIN==*(ptr_pin+i))
        {
            printf("Deposit Amount: \n");
            scanf("%f",&money);

            while(money<1)
            {
                printf("Deposit Error! Please deposit at least $1: \n");
                scanf("%f", &money);
            }
            *(ptr_bal+i)+=money;//adding money to index

        }

    }
    return 1;
}
int withdraw(int*ptr_pin, float*ptr_bal, int account){
    float money=0;
    int PIN=0;
    int i;

    printf("Account PIN: \n");
    scanf("%d", &PIN);
    for(i=0;i<account;i++){
        if (PIN!= *(ptr_pin+i))
        {
            return 0;//if pin doesn't match
        }
        else {
            printf("Withdrawal Amount: \n");
            scanf("%f", &money);

            if (money>*(ptr_bal+i))//money cannot be greater than account balance
            {
                printf("Insufficient funds!\n");
                return 0;
            }
            else
            {
                *(ptr_bal+i)-=money;//subtracting money from index
                return 1;
            }
        }


    }
    return 0;
}
void summary(int*ptr_pin, float*ptr_bal, int account){
    int i;
    int num=1;
    printf("****************************\n Active Account Summary\n ****************************\n");
    for(i=0;i<account;i++,num++)
    {
        printf("Account #%d\t%d\t$%f\n",num,*(ptr_pin+i),*(ptr_bal+i));
    }

}

