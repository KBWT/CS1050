//Katherine Thomas
//kbthxz
//CS1050 HW2 

#include <stdio.h>

char getCounter(void);//function prototype
char game(char, char);//function prototype
void printBoard();//function prototype
int turn(char, int);//function prototype
int victory(char, int);//function prototype

char board[6][7] = {{'-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-'},};
int main (){
    char player1;
    char player2;

    printf("Player 1, ");
    player1=getCounter();
    printf("Player 2, ");
    player2=getCounter();

    if(player1==player2){
        printf("Both players have the same letter. Pick another letter!: \n");
        player2=getCounter();
    }

    char winner=game(player1, player2);
    printf("Player %c won!!!! Good Job!\n", winner);

    return 0;
}

char getCounter(){
    char letter;//define player's marker
    printf("please enter your letter (A-Z): \n");
    scanf("%c", &letter);
    getchar();

    while( letter<65 || letter>90){
        printf("Invalid key entered! Please enter your letter (A-Z): \n");
        scanf("%c", &letter);
    }
    return letter;
}

char game(char player1,char player2){
    int move=0;//player's marker drop
    int spaces=42;

    while (1){
        printf("%c, your turn.\n", player1);//player1
        printf("Enter a column to drop into (0-6): \n"); //column
        scanf("%d", &move);

        while(move<0 || move>6){//error check columns for 0-6
            printf("Error! That column does not exist. %c, re-enter a column: ", player1);
            scanf("%d", &move);
        }

        int yesvictory=turn(player1,move);
        spaces--;
        if (board[0][move]!='-'){
            printf("Column Full! Choose another one!(0-6): \n");//error checking
            scanf("%d", &move);
        }
        printBoard();//prints the current board
        if (yesvictory==1 || spaces==0){
            return player1;
        }

        printf("%c, your turn.\n", player2);//player2
        printf("Enter a column to drop into: \n");//column
        scanf("%d",&move);

        while(move<0 || move>6){//error checks columns for 0-6
            printf("Error! That column does not exist. %c, re-enter a column: ", player2);
            scanf("%d", &move);
        }

        yesvictory=turn(player2,move);
        spaces--;
        if (board[0][move]!='-'){
            printf("Column Full! Choose another one!: \n");
            scanf("%d",&move);
        }
        printBoard();//prints current board
        if(yesvictory==1 || spaces==0){
            return player2;
        }
    }
}

void printBoard(){
    int i;//initialize variable
    int j;//initialize variable
    for(i=0;i<6;i++){
        for(j=0;j<7;j++){
            printf("%c",board[i][j]);
        }
        printf("\n"); //row
    }
}

int turn (char gamer,int index){
    int i=0;//initialize variable
    for(i=5;i>=0;i--){
        if(board[i][index]=='-'){
            board[i][index]=gamer;
            break;
        }
    }
    return victory(gamer,index);
}

int victory(char gamer, int column){
    int counter=0; //intialize variable
    int i=0;//row check
    int j=0;//column check 

    for(i=0;i<6;i++){//vertical columns
        if(board[i][column]==gamer){
            counter++;
            if (counter==4){
                return 1;
            }
        }
        else{
            counter=0;
        }
    }

    counter = 0;

    for(i=0;i<6;i++){
        for(j=0;j<7;j++){//horizontal columns
            if(board[i][j]==gamer){
                counter++;
                if (counter==4){
                    return 1;
                }
            }
            else{
                counter=0;
            }
        }

    }
    return 0;
}
