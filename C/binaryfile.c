#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]){
	FILE *target;
	target = fopen(argv[1], "wb");
	int i = 12;
//	for (int i = 64; i < 70; ++i)
//	{
		/* code */
		fwrite(&i, sizeof(int), 1, target);

//	}
	
	fclose(target);	
}