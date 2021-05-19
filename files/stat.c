#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int numarg, char **argv){

    //Verifica si viene un parametro más
	if(numarg == 2){
        char *path = argv[1];
        struct stat sb;
        //Verifica si existe el archivo
        if(stat(path,&sb) == -1){
    		printf("El archivo no existe :(\n");
            return -1;
        }
        if(S_ISDIR(sb.st_mode)){
		    printf("Es un directorio.\n"); 
        }

        if(S_ISREG(sb.st_mode)){
		    printf("Es un archivo.\n"); 
        }
	}else{
		printf("Error: Ingrese argumentos validos\n");
	}
	
	return 0;
}