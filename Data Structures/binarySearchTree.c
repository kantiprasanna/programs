#include<stdio.h>

struct node{
	int number;
	struct node *leftChild;
	struct node *rightChild;	
};

void traverse(struct node *root);
void insert();
void printInorder(struct node *root);
struct node* leftLeaf(struct node *root);
void delete();
void f(struct node *root);
void f1(struct node *root);

struct node *root = NULL, *newNode, *temp, *found, *foundBefore;
int value, deletedElement;

int main(int argc, char const *argv[]){
	int choice;
	while(1){
		printf("1.Add elememt.\n2.Delete element.\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: insert();
					break;
			case 2: delete();
			 		break;
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

void delete(){	
	printf("Enter element to be deleted: ");
	scanf("%d", &deletedElement);
	f(root);
	f1(root);
	printf("found = %d, foundBefore = %d", found -> number, foundBefore -> number);
	if(found -> leftChild == NULL && found -> rightChild == NULL){
		if(foundBefore -> leftChild -> number == deletedElement)
			foundBefore -> leftChild = NULL;
		else
			foundBefore -> rightChild = NULL;
	}
	else if(found -> leftChild == NULL){
		if(foundBefore -> leftChild -> number == deletedElement)
			foundBefore -> leftChild = found -> rightChild;
		else
			foundBefore -> rightChild = found -> rightChild;
	}
	else if(found -> rightChild == NULL){
		if(foundBefore -> leftChild -> number == deletedElement)
			foundBefore -> leftChild = found -> leftChild;
		else
			foundBefore -> rightChild = found -> leftChild;
	}
	else{
		if(foundBefore -> leftChild -> number == deletedElement){
			foundBefore -> leftChild = found -> rightChild;
			temp = leftLeaf(found -> rightChild);
			temp -> leftChild = found -> rightChild;
		}
		else{
			foundBefore -> rightChild = found -> rightChild;
			temp = leftLeaf(found -> rightChild);
			temp -> leftChild = found -> leftChild; 
		}
	}
	
}

void f(struct node *root){
	if(root -> number == deletedElement)
		found = root;
	// else if(root -> leftChild -> number == deletedElement || root -> rightChild -> number == deletedElement)
	// 	foundBefore = root;
	else if(root -> number < deletedElement && root -> rightChild != NULL)
		f(root -> rightChild);
	else if(root -> number > deletedElement && root -> leftChild != NULL)
		f(root -> leftChild);
	else 
		return;
}

void f1(struct node *root){
	// if(root -> number == deletedElement)
	// 	found = root;
	if(root -> leftChild -> number == deletedElement || root -> rightChild -> number == deletedElement)
		foundBefore = root;
	else if(root -> number < deletedElement && root -> rightChild != NULL)
		f1(root -> rightChild);
	else if(root -> number > deletedElement && root -> leftChild != NULL)
		f1(root -> leftChild);
	else 
		return;
}

struct node* leftLeaf(struct node *root){
	// if(root -> leftChild != NULL)
	// 	t = leftLeaf(root -> leftChild);
	while(root -> leftChild != NULL){
		root = root -> leftChild;
	}
	return root;
}