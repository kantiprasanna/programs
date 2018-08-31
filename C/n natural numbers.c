#include <stdio.h>

int main(int argc, char const *argv[])
{
	int lastNumber, sum = 0, counter = 1;
	printf("Enter the last number upto which sum is required: ");
	scanf("%d", &lastNumber);
	while(counter <= lastNumber){
		sum += counter;
		counter++;
	}
	printf("Sum of first %d Natural numbers is %d.\n", lastNumber, sum);
	return 0;
}