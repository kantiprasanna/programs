#include <stdio.h>

int main(void) {
  int number, sum = 0;
  printf("Enter the number upto which sum of multiples of 3 and 5 is required: ");
  scanf("%d", &number);
  for(int i = 1; i < number; i++){
    if((i % 3 == 0) || (i % 5 == 0)){
      sum += i;
    }
  }
  printf("The sum of all multiples of 3 and 5 upto %d is %d.", number, sum);
   return 0;
}