//Katherine Thomas, Kbthxz, 8/26/17//

#include <stdio.h>

//Function main begins program execution//
int main( void )
{
	int num1; //first number from user input//
	int num2; //second number from user input// 
	int sum; //sum of both numbers from user input//
	int difference; //difference of both numbers from user input//

	printf( "Enter the first integer: \n");//prompt//
	scanf( "%d", &num1 ); //reads first integer//

	printf( "Enter the second integer: \n");//prompt//
	scanf( "%d", &num2 ); //reads second integer//
	
	sum = num1 + num2; //assigns total to sum//
	difference= num1 - num2; //assigns total to difference//

	printf( "Sum of the two integers is: %d \n", sum); //prints sum//
	printf( "The difference of the two integers is: %d \n", difference); //prints difference//

	if (num1 == num2) {
		printf( "%d is equal to %d\n", num2, num2);
	} //end if//

	if ( num1 != num2 ) {
		printf("%d is not equal to %d\n", num1, num2 );
	} //end if//

	if (num1 < num2) {
		printf( "%d is less than %d\n", num1, num2);
	} //end if//

	if (num1 > num2) {
		printf( "%d is greater than %d\n", num1, num2);
	} //end if//

	return 0; //indicates that program ended successfully//
} //end function main//


		
