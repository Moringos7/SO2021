#include <stdio.h>

int main(int numarg, char **argv){
	//El uno es por las palabras en el comando
	if(numarg != 1){
		for(int i  = numarg - 1 ; i > 0; i--){
			printf("%s ",argv[i]);	
		}	
	}else{
		printf("Error: Sin argumentos no trabajo :/");
	}
	
	printf("\n");
	return 0;
}