//Katherine Thomas
//kbthxz
//CS 1050 HW 1

#include <stdio.h>

int main ( void ) //begins program execution
{
	int studentid; //variable for user's student id
	int credithr; //variable for user's number of credit hours
	int resident; // variable for user's resident input
	int engineering; //variable for credit hours in College of Engineering
	float grants; //variable for grants and scholarships
	float base;//variable for tution
	float totalt;//variable for tuition leftover after grants applied

	printf( "Enter a student ID number (8 digits beginning with '1'): " );//prompt
	scanf( "%d", &studentid);
	while ( studentid != 0 ) {

	while (10000000>studentid || 19999999< studentid){
		printf("Please enter a valid student ID number: \n ");//warning
		scanf( "%d", &studentid );
	}
	printf( "How many credit hours is this student enrolled in?: ");//prompt2
	scanf( "%d", &credithr);// reads credit hours 

	base= credithr * 282.00;
	
	printf( "Is this student an out-of-state resident? Enter '1' for yes, any other value for no: \n");
	scanf( "%d", &resident);//reads for resident or foreigner

	if (1==resident) {
		base+= 557.30 * credithr;
	}
	
	printf( "How many credit hours are within the College of Engineering?: \n");//prompt3
	scanf( "%d", &engineering);// reads for credit hours in engineering

	while (credithr< engineering){ //ensures that credit hours are within limit
		printf(" Credit hours within the College of Engineering cannot exceed total credit hours the student is enrolled in! \n"); 
		printf("Re-enter credit hours within the College of Engineering: \n"); //warning2
		scanf( "%d", &engineering); //re-reads for credit hours in engineering
	}

	base+= 90 * engineering;
	
	printf( "Total grant or scholarship funds for this student (dollars): \n"); //prompt4
	scanf( "%f", &grants);//reads for grants 

	while (grants> base){ //ensures that scholarships do not exceed the tuition
		printf (" The scholarship total cannot exceed the tuition total! \n"); //warning3
	
		printf("Total grant or scholarship funds for this student (dollars): \n");
		scanf("%f", &grants); //re-reads for grants
	}

	printf( "***** TUITION STATEMENT ***** \n");//summary starts

	printf("Student ID:  %d \n", studentid);
	printf("Credit Hours: %d \n", credithr);
	
	printf("***** \n");
	
	printf("Base tuition: %.2f \n", base);
	printf("Scholarships and grants: %.2f \n", grants);
	
	totalt= base - grants; //tuition left over after grants
	printf("***** \n");
	
	printf("Tuition Grand Total: %.2f \n", totalt);
	
	printf ("Please re-enter another student ID, otherwise enter '0': \n");
	scanf("%d", &studentid);
	} 
	 
	return 0; //program ends
}
