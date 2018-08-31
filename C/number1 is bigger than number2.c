#include <stdio.h>

int main(int argc, char const *argv[])
{
	int firstNumber, secondNumber;
	char message[20] = "is bigger than";
	printf("Enter first number: ");
	scanf("%d", &firstNumber);
	printf("Enter second number: ");
	scanf("%d", &secondNumber); 
	if(firstNumber > secondNumber){
		printf("%d %s %d", firstNumber, message, secondNumber);
			}
	else{
		printf("%d %s %d", secondNumber, message, firstNumber);	
			
		
	}
	return 0;
}