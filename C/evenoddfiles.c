#include<stdio.h>

void main(int argc, char *argv[]){
	FILE *even, *odd;
	even = fopen(argv[1], "w");
	odd = fopen(argv[2], "w");
	for(int i = 1; i < asciiConversion(argv[3]); i++){
		if(i % 2 == 0){
			fprintf(even, "%d\n", i);
		}
		else{
			fprintf(odd, "%d\n", i);	
		}
	}
	fclose(even);
	fclose(odd);
}

int asciiConversion(char v[]){
	int result = 0;
	for (int i = 0; v[i] != '\0'; ++i){
        if((v[i] >= 48)&&(v[i] <= 57))
        result = result*10 + v[i] - '0';
        //printf("\nDEBUGG:  %d", result);
	}
    return result;
}