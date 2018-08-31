#include <stdio.h>

struct node{
	int number;
	struct node *nextAddress;

};

struct node *head = NULL;

void addNode(){
	struct node *new = (struct node *)malloc(sizeof(struct node));
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	if(head == NULL){
		
		printf("Enter number which is to be added in list: ");
		scanf("%d", &temp -> number);
		temp -> nextAddress = NULL;
		head = temp;
	}
	else{
		temp = head;
		while(temp -> nextAddress != NULL){
			temp = temp -> nextAddress;
		}
		printf("Enter number which is to be added in list: ");
		scanf("%d", &new -> number);
		temp -> nextAddress = new;
		new -> nextAddress = NULL;
	}
}

void display(){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp = head;

	while(temp -> nextAddress != NULL){
		// printf("%d -> ", temp -> number);
		printf("%d %u\n", temp -> number, temp -> nextAddress);
		temp = temp -> nextAddress;
	}
	printf("%d", temp -> number);
}

int main(int argc, char const *argv[]){
	int choice, counter = 0;
	while(1){
		if(counter == 5){
			printf("Elements in linked list are 5. You cannot add more.");
			break;

		}
		else{
			printf("1.Add number.\n2.Display\n");
			printf("Enter choice: ");
			scanf("%d", &choice);
			switch(choice){
				case 1: addNode();
						display();
						printf("\n");
						counter++;
						break;
				case 2: display();
						printf("\n");
						break;
				default: exit(1);
			}
		}
	}
	return 0;
}
