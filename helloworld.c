#include <stdio.h>
//Compila con: gcc <file.c> -o <file exe>

int main(int numarg, char **argv){
	//El uno es por las palabras en el comando
	printf("Hola: ");
	for(int i  = 1; i < numarg; i++){
		printf("%s ",argv[i]);	
	}
	printf("\n");
	return 0;
}