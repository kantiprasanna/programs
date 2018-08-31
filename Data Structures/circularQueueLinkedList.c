#include<stdio.h>

// queue add at last and remove at first.....

struct node{
	int number;
	struct node *nextAddress;
};

struct node *head = NULL;

void display(){
	struct node *temporaryNode;
	// temporaryNode = (struct node *)malloc(sizeof(struct node));
	temporaryNode = head;
	if(head == NULL){
		printf("Empty queue.\n");
	}
	else if(head -> nextAddress == head){
		printf("%d\n", head -> number);
	}
	else{
		while(temporaryNode -> nextAddress != head){			
			// while(temporaryPointer != NULL){
			if(temporaryNode == head){
				printf("%d ", temporaryNode -> number);
				temporaryNode = temporaryNode -> nextAddress;
			}
			else{
				printf(" -> %d ", temporaryNode->number);
				temporaryNode = temporaryNode->nextAddress;
				
			}						
		}
		printf(" -> %d\n", temporaryNode -> number);
	}
}

void insert(){
	int value;
	struct node *temporaryNode = (struct node *)malloc(sizeof(struct node));
	struct node *new = (struct node *)malloc(sizeof(struct node));
	printf("Enter a number to be inserted: ");
	scanf("%d", &value);
	if(head == NULL){
		temporaryNode -> number = value;
		temporaryNode -> nextAddress = temporaryNode;
		head = temporaryNode;
	}
	else{
		temporaryNode = head;
		while(temporaryNode -> nextAddress != head){
			temporaryNode = temporaryNode -> nextAddress;
		}
		new -> number = value;
		temporaryNode -> nextAddress = new;
		new -> nextAddress = head;
		
		
	}
}

void delete(){
	struct node *temporary, *temporaryNode;
	if(head == NULL){
		printf("Underflow.\n");
	}
	else if(head -> nextAddress == head){
		printf("Element which is being deleted is %d.\n", head -> number);
		head = NULL;
	}
	else{
		temporary = head;
		temporaryNode = head; 
		printf("Element which is being deleted is %d.\n", head -> number);
		while(temporary -> nextAddress != head){
			temporary = temporary -> nextAddress;
		}
		// temporary -> nextAddress = head;
		head = head -> nextAddress;
		temporary -> nextAddress = head;
		free(temporaryNode);
	}
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