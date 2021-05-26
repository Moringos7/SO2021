#include "./student.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv){
    if(argc == 3){
        char *filename = argv[1];
        int records = atoi(argv[2]);
        FILE * forigen;
        forigen = fopen(filename,"rb");

        STUDENT newStudent;
        int cont = 0;
        while(fread(&newStudent,sizeof(newStudent),1,forigen) && cont < records){
            printf("Estudiante #%d \n",++cont);
            printf("Nombre: %s\n",newStudent.name);
            printf("Apellido: %s\n",newStudent.lastName);
            printf("ID: %d\n",newStudent.id);
            printf("Semestre: %d \n",newStudent.semestre);
        }            

        if(cont != records){
            printf("Solo contamos con %d registros. \n",cont);
        }
        
        fclose(forigen);
    }else{
		printf("Error: Ingrese argumentos validos\n");
	}
    return 0;
}