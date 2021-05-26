#include "./student.h"
#include <stdio.h>

int main(int argc, char**argv){
    if(argc == 2){
        char *filename = argv[1];
        
        FILE * forigen;
        forigen = fopen(filename,"rb");

        STUDENT newStudent;
        int cont = 0;
        while(fread(&newStudent,sizeof(newStudent),1,forigen)){
            printf("Estudiante #%d \n",++cont);
            printf("Nombre: %s\n Apellido: %s\n - ID: %d\n - Semestre: %d \n",newStudent.name,newStudent.lastName,newStudent.id,newStudent.semestre);
        }            
        
        fclose(forigen);
    }else{
		printf("Error: Ingrese argumentos validos\n");
	}
    return 0;
}