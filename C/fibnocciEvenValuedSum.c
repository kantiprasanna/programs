// sum of all the even-valued terms in the sequence which do not exceed one million.

#include <stdio.h>

int fib(int number);
int main(void) {
  int termNumber, sum = 0, i;
  printf("Enter number of terms in series: ");
  scanf("%d", &termNumber);
  for(int i = 2; i <= termNumber; i += 3){
    sum += fib(i);
  }
  printf("Sum of even valued terms among %d terms is %d.", termNumber, sum);
  return 0;
}

int fib(int number){
  if(number == 1){
    return 1;
  }
  if(number == 2){
    return 2;
  }
  return fib(number - 1) + fib(number - 2);
}