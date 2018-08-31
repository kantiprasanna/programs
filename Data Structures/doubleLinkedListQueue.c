#include<stdio.h>

// queue add at last and remove at first.....

struct node{
	struct node *previousAddress;
	int number;
	struct node *nextAddress;
};

struct node *head = NULL;

void display(){
	struct node *temporaryNode;
	temporaryNode = head;
	if(head == NULL){
		printf("Empty queue.\n");
	}
	else{
		while(temporaryNode != NULL){			
			if(temporaryNode == head){
				printf("%d ", temporaryNode -> number);
				temporaryNode = temporaryNode -> nextAddress;
			}
			else{
				printf(" -> %d ", temporaryNode->number);
				temporaryNode = temporaryNode->nextAddress;
				
			}
			
		}
	}
}

void insert(){
	int value;
	struct node *temporaryNode = (struct node *)malloc(sizeof(struct node));
	struct node *new = (struct node *)malloc(sizeof(struct node));
	printf("Enter a number to be inserted: ");
	scanf("%d", &value);
	if(head == NULL){
		temporaryNode -> previousAddress = NULL;
		temporaryNode -> number = value;
		temporaryNode -> nextAddress = NULL;
		head = temporaryNode;
	}
	else{
		temporaryNode = head;
		while(temporaryNode -> nextAddress != NULL){
			temporaryNode = temporaryNode -> nextAddress;
		}
		// temporaryNode -> nextAddress = new;
		new -> previousAddress = temporaryNode;
		new -> number = value;
		temporaryNode -> nextAddress = new;
		new -> nextAddress = NULL;
		
		
	}
}

void delete(){
	struct node *temporary;
	temporary = head; 
	printf("Element which is being deleted is %d.\n", head -> number);
	head = head -> nextAddress;
	head -> previousAddress = NULL;
	free(temporary);
}

int main(int argc, char const *argv[]){
	int choice;
	while(1){
		printf("1.Add element.\n2.Delete element.\n3.Display element.\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: insert();
					display();
					printf("\n");
					break;
			case 2: delete();
					display();
					printf("\n");
					break;
			case 3: display();
					printf("\n");
					break;
			default: exit(1);
		}
	}
	return 0;
}