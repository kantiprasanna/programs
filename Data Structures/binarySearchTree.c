#include<stdio.h>

struct node{
	int number;
	struct node *leftChild;
	struct node *rightChild;	
};

void traverse(struct node *root);
void insert();
void printPreorder(struct node *root);

struct node *root = NULL, *newNode, *temp;
int value;

int main(int argc, char const *argv[]){
	int choice;
	while(1){
		printf("1.Add elememt.\n2.Delete element.\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: insert();
					break;
			// case 2: delete();
			// 		break;
			case 3: printInorder(root);
					break;
		}
	}
	return 0;
}

void insert(){
	printf("Enter number: ");
	scanf("%d", &value);
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode -> number = value;
	newNode -> leftChild = NULL;
	newNode -> rightChild = NULL;
	if(root == NULL)
		root = newNode;
	else{
		traverse(root);
	}
}

void traverse(struct node *root){
		temp = root;
		if(root == NULL)
			return;
		if(temp -> number < value && temp -> rightChild == NULL)
			temp -> rightChild = newNode;
		else if(temp -> number > value && temp -> leftChild == NULL)
			temp -> leftChild = newNode;
		else if(temp -> number > value)
			traverse(temp -> leftChild);
		else if(temp -> number < value)
			traverse(temp -> rightChild);
}

void printInorder(struct node *root){
	// preorder
	if(root == NULL)
		return;
	printInorder(root -> leftChild);	
	printf("%d ", root -> number);	
	printInorder(root -> rightChild);
}