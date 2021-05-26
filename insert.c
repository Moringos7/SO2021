#include "./student.h"
#include <stdio.h>

int main(int argc, char**argv){
    if(argc == 2){
        char *filename = argv[1];
        int cuantos;
        printf("Cuantos alumnos a insertar?: ");
        scanf("%d",&cuantos);
        
        FILE * fdestino;
        fdestino = fopen(filename,"wb");

        for(int i=0; i< cuantos; i++){
            printf("Estudiante # %d \n",i+1);
            STUDENT newStudent;
            printf("Nombre: ");
            scanf("%s",newStudent.name);
            printf("Apellido: ");
            scanf("%s",newStudent.lastName);
            printf("ID: ");
            scanf("%d",&newStudent.id);
            printf("Semestre: ");
            scanf("%d",&newStudent.semestre);
            fwrite(&newStudent,sizeof(newStudent),1,fdestino);
            //printf("%s - %s - %d - %d \n",newStudent.name,newStudent.lastName,newStudent.id,newStudent.semestre);
            
        }
        fclose(fdestino);
    }else{
		printf("Error: Ingrese argumentos validos\n");
	}
    return 0;
}