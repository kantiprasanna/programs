#include <stdio.h>
#include<time.h>
#include <math.h>

int counter = 2, count;
double totalTime1, totalTime2;
clock_t start1, end1, start2, end2;

int prime1(int number);
int prime2(int number);

int main(int argc, char const *argv[]){
	int number, check1, check2;
	printf("Enter a number greater than 1: ");
	scanf("%d", &number);
	char message1[30] = "is a prime number.";
	char message2[30] = "is not a prime number.";
	int counter1 = 0, counter2 = 0;
	start1 = clock();
	for (int i = 2; i <= number; ++i){
		check1 = prime1(i);
		if(check1 == 0){
			counter1++;
		}
	}
 	
 	end1 = clock();
 	totalTime1 = (double)(end1 - start1)/CLOCKS_PER_SEC;

	// if(check1 == 0)
	// 	printf("%d %s\n", number, message1);
	// else
	// 	printf("%d %s\n", number, message2);

	start2 = clock();
	for (int i = 2; i <= number; ++i){
		check2 = prime2(i);
		if(check2 == 0){
			counter2 =counter2 + 1;
		}
	}
	end2 = clock();
	totalTime2 = (double)(end2 - start2)/CLOCKS_PER_SEC;
	// if(check2 == 0)
	// 	printf("%d %s", number, message1);
	// else
	// 	printf("%d %s", number, message2);
	printf("Fun1 = %lf, Fun2 = %lf", totalTime1, totalTime2);
	printf(" \nPrime1 %d\n Prime2 %d.", counter1, counter2);
	return 0;
}

int prime1(int number){
	count = number / 2;
	counter = 2;
	while(counter < count){
		if(number % counter == 0){
			return 1;
		}
		counter++;
	}
	return 0; 
}

int prime2(int number){
	count = sqrt(number);
	counter = 2;
	while(counter < count){
		if(number % counter == 0){
			return 1;
		}
		counter++;
	}
	return 0; 	
}