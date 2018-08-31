#include<stdio.h>

void main(int argc, char *argv[]){
	FILE *target;
	target = fopen(argv[1], "r+");
	for (int i = 0; i < argc; ++i)
	{
		printf("DEBUG: argv[%d] - %s \n", i, argv[i]);
		/* code */
	}
	fprintf(target, "I am commited.");
	fclose(target);
}