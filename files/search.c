#include "./student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char**argv){
    if(argc == 4){
        //archivo
        char *filename = argv[1];
        //atributo
        char *atributo = argv[2];

        FILE * forigen;
        forigen = fopen(filename,"rb");
        STUDENT newStudent;
        int found = 0;
        int cont = 0;
        while(fread(&newStudent,sizeof(newStudent),1,forigen)){

            if(strcmp(atributo, "name") == 0){
                if(strcmp(newStudent.name, argv[3]) == 0){
                    found = 1;
                }
            } else if(strcmp(atributo, "lastname") == 0){
                if(strcmp(newStudent.lastName, argv[3]) == 0){
                    found = 1;
                }
            } else if(strcmp(atributo, "id") == 0){
                if(newStudent.id == atoi(argv[3])){
                    found = 1;
                }
            } else if(strcmp(atributo, "semestre") == 0){
                if(newStudent.semestre == atoi(argv[3])){
                    found = 1;
                }
            }else{
                printf("El atributo %s no se encuentra en los registros, pruebe con otro.\n",atributo);
                break;
            }

           //Impresión de coincidencias
            if(found){
                printf("Coincidencia #%d \n",++cont);
                printf("Nombre: %s\n",newStudent.name);
                printf("Apellido: %s\n",newStudent.lastName);
                printf("ID: %d\n",newStudent.id);
                printf("Semestre: %d \n",newStudent.semestre);
                printf("---------------------\n");
                found = 0;
            }
        }            
        if(cont == 1){
            printf("\n%d Coincidecia.\n\n",cont);
        }else{
            printf("\n%d Coincidecias.\n\n",cont);
        }
        
        fclose(forigen);
    }else{
		printf("Error: Ingrese argumentos validos\n");
	}
    return 0;
}