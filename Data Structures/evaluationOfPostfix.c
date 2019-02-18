#include <stdio.h>
#include <string.h>
// #include "infixtopostfix.c"
#define MAX 20
int top = -1;
float stack[20];
float values[20];


void push(float stack[], float value){
	if(top == MAX - 1){
		printf("Stackoverflow.");
	}
	else{
		top++;
		stack[top] = value;
	}
}

float pop(float stack[]){
	float value = -1;
	if(top == - 1){
		printf("Stack Underflow.");
	}
	else{
		value = stack[top];
		top--;
	}
	return value;
}

// void readValues(char postfixExpression[], float values[]){
// 	int counter; 
// 	int length;
// 	length = strlen(postfixExpression);
// 	for(int i = 0; i < length; i++){
// 		if(isalpha(postfixExpression)){
// 			counter++;
// 		}
// 	}
// 	for(int i = 0; i < counter; i++){
// 		printf("Enter number: ");
// 		scanf("%f", &values[i]);
// 	}
// }

float evaluatePostfixToPrefix(char postfixExpression[], float stack[], float values[]){
	int i = 0, j = 0;
	float op1, op2, result;
	while(postfixExpression[i] != '\0'){
		if(isalpha(postfixExpression[i])){
			scanf("%f", &values[j]);
			push(stack, values[j]);
			j++;
		}
		else{
			op2 = pop(stack);
			op1 = pop(stack);
			switch(postfixExpression[i]){
				case '+': result = op1 + op2;
						  break;
			 	case '-': result = op1 - op2;
						  break;
				case '*': result = op1 * op2;
						  break;
				case '/': result = op1 / op2;
						  break;
			}
			push(stack, result);
		}
		i++;
	}
	return pop(stack);
}

int main(int argc, char const *argv[])
{
	float val;
	char postfixExpression[20];
	printf("Enter postfix expression: ");
	gets(postfixExpression);
	val = evaluatePostfixToPrefix(postfixExpression, stack, values);
	printf("The value of postfix expression is %f.", val);
	return 0;
}

