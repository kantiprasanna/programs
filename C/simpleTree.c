#include <stdio.h>

struct node{
	int number;
	struct node *leftChild;
	struct node *rightChild;
	
};

struct node *createNodeWithValue(int value);

int main(int argc, char const *argv[]){
	int number;
	int number2, number3;
	struct node *root;
	printf("Enter a value: ");
	scanf("%d", &number);
	printf("Enter left value: ");
	scanf("%d", &number2);
	printf("Enter right value: ");
	scanf("%d", &number3);
	root = createNodeWithValue(number);
	root->leftChild = createNodeWithValue(number2);
	root->rightChild = createNodeWithValue(number3);
	printf("Node = %d\nLeft child = %d\nRight child = %d", root->number, root->leftChild->number, root->rightChild->number);
	free(root->rightChild);
	free(root->leftChild);
	free(root);
	return 0;
}

struct node *createNodeWithValue(int value) {
	struct node *node1;
	node1 = (struct node *)malloc(sizeof(struct node));
	node1->number = value;
	node1->leftChild = NULL;
	node1->rightChild = NULL;	
	return node1;
}

