#include <stdio.h>

int main(int argc, char const *argv[]){
	int number, counter = 1, square = 1;
	printf("Enter the number of terms to be printed in series: ");
	scanf("%d", &number);
	if(number <= 0){
		printf("Enter a positive number.");
		exit(1);
	}
	else if(number == 1){
		printf("First number in series is 1.");
		exit(1);
	}
	else{
		printf("First %d natural numbers in series are 1", number);
		while(counter < number){
			counter++;
			square = counter * counter;
			printf(", %d", square);
		}
		printf(".");
	}

	return 0;
}