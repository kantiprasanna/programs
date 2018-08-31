// insert an element in an array at a particular location


#include <stdio.h>
#define MAX 5

int start = -1, end = -1, queue[MAX][2];

void add(){
	int temp;
		if(end == MAX - 1){
			printf("Queue overflow.");	
		}
		else{
			if(start == -1)
				start = 0;
			end++;
			printf("Enter number to be added and its : ");
			scanf("%d%d", &queue[end][0], &queue[end][1]);
			for(int i = 0; i <= end; i++){
				for(int j = 0; j <= end - i - 1; j++){
					if(queue[j][1] > queue[j + 1][1]){
						temp = queue[j][1];
						queue[j][1] = queue[j + 1][1];
						queue[j + 1][1] = temp;
						temp = queue[j][0];
						queue[j][0] = queue[j + 1][0];
						queue[j + 1][0] = temp;
					}
				}
			}
		}
}

void delete(){
	if((start > end)||(end == -1)){
		printf("Queue underflow.\n");
	}
	else{
		printf("The element which is deleted is %d.\n", queue[start][0]);
		start++;
		printf("Debugg: start = %d\n", start);	
	}
	
}

void display(){
	for(int i = start; i <= end; i++){
		for(int j = 0; j < 2; j++){
			printf("%d ", queue[i][j]);
		}
		printf("\n");
	}
	// for (int i = 0; i < 2; i++){
	// 	for(int j = 0; j <= end; j++){
	// 		printf("%d ", queue[i][j]);
	// 		printf("DEBUGG: i = %d, j= %d", i, j);
	// 	}
	// 	printf("\n");
	// }
}

int main(int argc, char const *argv[])
{
	int choice, size;
	
	while(1){
		printf("1.Add element\n2.Delete element\n3.Display elements\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: add();
					display(queue);
					break;
			case 2: delete();
					display(queue);
					break;
			case 3: display(queue);
					break;
			default: exit(1);
		}
	}
	return 0;
}