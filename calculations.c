//Katherine Thomas
//kbthxz
//CS1050 Lab2

#include <stdio.h>
#include <math.h>

int main (void)
{
	int integer1; //first number input by user
	int integer2; //second number input by user
	int sum; //variable in which sum will be stored
	int difference; //variable in which difference will be stored
	int product; //variable in which product will be stored
	int exponent; //integer1 raised by integer2
	
	printf( "Enter the first integer: "); //prompt
	scanf("%d", &integer1);

	while (1>integer1 || 9<integer1) {
		printf(" The number must be between 0 and 10! \n " );//warning
		
		printf(" Re-enter the first integer:  ");
		scanf( "%d", &integer1 ); //re-reads first integer
		}


	printf( "Enter the second integer: "); //prompt
        scanf( "%d", &integer2 ); //reads second integer

	while ( 1>integer2 || 9<integer2) {
		printf ("The number must be between 0 and 10!\n "); //warning

		printf("Re-enter the second integer: ");
		scanf("%d", &integer2 ); //re-reads second integer
}

	sum = integer1 + integer2; //assigns total to variable
	difference= integer1 - integer2; //assigns difference to variable
	product= integer1* integer2; //assigns product to variable
	
	printf( "Sum of the two integers is: %d\n", sum); //prints sum
	printf( "Difference of the two numbers is %d\n", difference); //prints difference
	printf( "Product of the two numbers is %d\n", product); //print product

	if (product%2 == 0) {
		printf( "The product of the two integers is an even number. \n");
}
	else{
		printf( "The product of the two integers is an odd number. \n");
}

	if ( integer1== integer2) {
		printf( "%d is equal to %d\n", integer1, integer2);
	} //end if 
	if ( integer1 <integer2) {
		printf( "%d is less than %d\n", integer1, integer2);
	} // end if
	if (integer1 >integer2) {
		printf( "%d is greater than %d\n", integer1, integer2);
} 
	exponent = pow(integer1, integer2);
	printf( "%d raised to the power of %d is %d", integer1, integer2, exponent);
	return 0;
}
