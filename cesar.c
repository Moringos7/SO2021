#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if(argc == 2){
        char  *palabra = "HOLA";
        int des = atoi(argv[1]);
        char newLetter;
        int cont = 0;
        while(cont < strlen(palabra)){
            int wordCode = palabra[cont] - 65;
            newLetter = ((wordCode + des) % 26) + 'A';
            printf("%c",newLetter);
            cont++;
        }
        printf("\n");
    }else{
        printf("Error: Ingresando Argumentos.\n");
    }
}
