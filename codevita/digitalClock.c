#include <stdio.h>

int main(int argc, char const *argv[]){
	digitalCLock();
	return 0;
}

void digitalCLock(){
	int time[6], input[9];
	for(int i = 0; i < 9; i++)
		scanf("%d", &input[i]);
	for (int i = 0; i < 9; i++){
		for(int j =0; j < 8 - i; j++){
			if(input[j] > input[j + 1]){
				temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp; 
			}
		}
	}
	for(int i = 0; i < 9; i++){
		if(input[i] == 2){
			time[0] = 2;
			for(int j = 8; j >= 0; j--){
				if(input[j] <= 4){
					time[1] = input[j];
					input[j] = 0;
					break;
				}
			}
			for(int j = 8; j >= 0; j--){
				if(input[j] <= 5){
					time[2] = input[j];
					input[j] = 0;
					break;
				}
			}
			for(int j = 8; j >= 0; j--){
				if(input[j] <= 9){
					time[3] = input[j];
					input[j] = 0;
					break;
				}
			}
		}

	}
}