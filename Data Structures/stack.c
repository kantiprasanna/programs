#include <stdio.h>

int top = 0, size1;

void push(int numbers[]);
void pop(int numbers[]);
int size(int numbers[], int size1);
void display(int numbers[]);

int main(int argc, char const *argv[]){
	int numbers[10], choice, check;
	printf("Enter the size of stack: ");
	scanf("%d", &size1);
	while(1){
		printf("1.Add element.\n2.Remove element.\n3.Check Stack is full.\n4.Check Stack is empty.\n5.Display.Enter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: push(numbers);
					display(numbers);
					// printf("\n");
					break;
			case 2: pop(numbers);
					display(numbers);
					// printf("\n");
					break;
			case 3: check = size(numbers, size1);
					if(check == 2)
						printf("Stack is full.\n");
					else 
						printf("Stack is not full.\n");
					break;
			case 4: check = size(numbers, size1);
					if(check == 3)
						printf("Stack is empty.\n");	
					else
						printf("Stack is not empty.");	
					break;
			case 5:	display(numbers);
					break;
			default : exit(1);
		}

	}
	return 0;
}

void push(int numbers[]){
	int number;
	if(top == size1){
		printf("Stack is full.\n");
	}
	else{
		printf("Enter element to be added: ");
		scanf("%d", &number);
		numbers[top] = number;
		top++;
	}
}

void pop(int numbers[]){
	if(top == 0){
		printf("Stack is empty.\n");		
	}
	else{
		printf("The element which is deleted is %d.\n", numbers[top - 1]);
		top--;
		
	}
}

void display(int numbers[]){
	for(int i = 0; i < top; i++){
		printf("%d  ", numbers[i]);
	}
	printf("\n");
}

int size(int numbers[], int size1){
	if(size1 == top){
		return 2;
	}
	else if(size1 == 0)
		return 3;
	else 
		return 4;
}