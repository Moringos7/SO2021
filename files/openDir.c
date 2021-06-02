
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char**argv){

    if(argc == 2){
        char *dirName = argv[1];
        DIR * dir = opendir(dirName);
        if(dir != NULL){
            struct dirent * dirContent;
            while(dirContent = readdir(dir)){
                printf("file: %s y está en %lu.\n",dirContent->d_name,dirContent->d_ino);
            }
            closedir(dir);
        }else{
    		printf("Error: No se logró abrir el directorio.\n");
        }
    }else{
		printf("Error: Ingrese argumentos validos.\n");
	}
    return 0;
}