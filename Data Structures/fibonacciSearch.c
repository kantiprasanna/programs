#include <stdio.h>


int i, size, numbers[10], fib[10], key;
int p, q, r, t;
void search(){
	int found = 0, reference;
	p = fib[i -1];
	q = fib[i - 2];
	r = fib[i - 3];
	reference = (size + 1) - (p + q);
	// if(key > numbers[p])
	// 	p = p + reference;	
	while(p != 0 && found == 0){
		if(key == numbers[p]){
			printf("Found");
			found = 1;
		}
		else if(key < numbers[p]){
			printf("key< numbers\n");
			if(r == 0)
				p = 0;
			else{
				p = p - r;
				t = q;
				q = r;
				r = t - r;
			}
		}
		else if(key > numbers[p]){
			printf("key > numbers\n");
			if(q == 1)
				p = 0;
			else{
				p = p + r;
				q = q - r;
				r = r - q;
			}
		}
	}	
	if(found == 0){
		printf("Not found");
	}
}

int main(int argc, char const *argv[]){
	printf("Enter size: ");
	scanf("%d", &size);
	printf("Enter numbers: ");
	for(int k = 0; k < size; k++)
		scanf("%d", &numbers[k]);

	fib[0] = 0;
	fib[1] = 1;
	i = 1;
	while(fib[i] < size){
		fib[i + 1] = fib[i] + fib[i - 1];
		i++;
	}
	printf("DEBUGG: ");
	for(int k = 0; k <= i; k++){
		printf("%d ", fib[k]);
	}
	printf("\n");
	printf("Ener search element: ");
	scanf("%d", &key);
	search();


	return 0;
}