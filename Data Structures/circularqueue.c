// All errors are fixed


#include <stdio.h>
#define MAX 5

int start = -1, end = -1, queue[MAX];

void display(int queue[]){
	if((start < 0)){
		printf("Empty queue.");
	}
	// else if(start == end){
	// 	printf("%d\n", queue[start]);
	// }
	else if(start > end){
		for(int i = start; i <= MAX - 1; i++){
			printf("%d ", queue[i]);
		}
		if(start > 0){
			for(int i = 0; i <= end; i++){
				printf("%d ", queue[i]);
			}
		}
	}
	// else if(start == end && start > 0){
	// 	printf("%d", queue[start]);
	// }
	else{
		for(int i = start; i <= end; i++){
			printf("%d ", queue[i]);
		}
	}
}

// Errors in insert are cleared..........

void insert(int queue[]){
	int value;
	
	if((start == 0)&&(end == MAX - 1)){
		printf("Queue is full.\n");
	}


	else if((end == MAX)&&(start != 0)){
		end = 0;
		printf("Enter number to be entered in queue: ");
		scanf("%d", &queue[end]);
		end++;
		
	}
	
	else if(((start > 0)&&(end == MAX - 1))){
		end = -1;
		end++;
		printf("Enter number to be entered in queue: ");
		scanf("%d", &queue[end]);
		
	}
	else if((start > 0)&&(end >= start)){
		printf("Queue is full.\n");

	}
	else{
		if((start == -1)||(end == -1)){
			start = 0;
			// end = 0;
		}
		end++;
		printf("Enter number to be entered in queue: ");
		scanf("%d", &queue[end]);
		// end++;
	}
}


void delete(int queue[]){
	if((start == -1)){
		printf("Underflow.\n");
	}
	else if(start == end){
		printf("Element which is removed is %d\n", queue[start]);
		start = -1;
		end = -1;
	}
	else{
		printf("Element which is removed is %d\n", queue[start]);
		start++;
		// if((start == MAX)){			
		// 	start = 0;
		// }

	}
}

int main(int argc, char const *argv[]){
	int choice, size;
	
	while(1){
		printf("1.Add element\n2.Delete element\n3.Display elements\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: insert(queue);
					// printf("\n start = %d end = %d\n", start, end);these a
					display(queue);
					printf("\n");
					break;
			case 2: delete(queue);
					// printf("\n start = %d end = %d\n", start, end);
					display(queue);
					printf("\n");
					break;
			case 3: display(queue);
					printf("\n");
					break;
			default: exit(1);
		}
	}
	return 0;
}



