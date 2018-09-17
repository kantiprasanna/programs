#include <stdio.h>

void swap(int *n1, int *n2){
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

int partition ( int numbers[],int start ,int end) {
    int i = start + 1;
    int piv = numbers[start] ;   
    for(int j = start + 1; j <= end ; j++ )  { 
        if(numbers[j] < piv){
            swap (&numbers[i], &numbers[j]);
            i += 1;
        }
   }
   swap(&numbers[start], &numbers[i-1]); 
   return i-1;             
}

void quickSort (int numbers[ ], int start, int end){
   if(start<end){ 
        int pivPos = partition (numbers, start, end ) ;     
        quickSort (numbers, start, pivPos -1); 
        quickSort (numbers, pivPos +1, end) ; 
    }
}

int main(int argc, char const *argv[]){
	int numbers[10], size;
	printf("Enter size: ");
	scanf("%d", &size);
	for(int i = 0; i < size; i++)
		scanf("%d", &numbers[i]);
	quickSort(numbers, 0, size - 1);
	for(int i = 0; i < size; i++)
		printf("%d ", numbers[i]);
	return 0;
}