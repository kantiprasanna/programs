#include<stdio.h>

int fib(int count){
	int number1 = 1, number2 = 2, sum;
	printf("First %d terms in series are 1, 2");
	for(int i = 0; i < count - 2; i++){
		sum = number1 + number2;
		number1 = number2; 
		number2 = sum;
		printf(", %d", number2);
	}
	printf(".");
	

}
int main(int argc, char const *argv[]){
	int count;
	printf("Enter number of terms required: ");
	scanf("%d", &count);
	fib(count);
	return 0;
}