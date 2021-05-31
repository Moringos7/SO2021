#include "./student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char**argv){
    if(argc == 5){
        //archivo
        char *filename = argv[1];
        //atributo
        char *atributo = argv[2];

        FILE * forigen;
        forigen = fopen(filename,"rb+");
        STUDENT newStudent;
        int updated = 0;
        int cont = 0;
        while(fread(&newStudent,sizeof(newStudent),1,forigen)){

            if(strcmp(atributo, "name") == 0){
                if(strcmp(newStudent.name, argv[3]) == 0){
                    strcpy(newStudent.name,argv[4]);
                    fseek(forigen, -1 * sizeof(newStudent),SEEK_CUR);
                    fwrite(&newStudent,sizeof(newStudent),1,forigen);
                    updated = 1;
                    break;
                }
            } else if(strcmp(atributo, "lastname") == 0){
                if(strcmp(newStudent.lastName, argv[3]) == 0){
                    strcpy(newStudent.lastName,argv[4]);
                    fseek(forigen, -1 * sizeof(newStudent),SEEK_CUR);
                    fwrite(&newStudent,sizeof(newStudent),1,forigen);
                    updated = 1;
                    break;
                }
            } else if(strcmp(atributo, "id") == 0){
                if(newStudent.id == atoi(argv[3])){
                    newStudent.id = atoi(argv[4]);
                    fseek(forigen, -1 * sizeof(newStudent),SEEK_CUR);
                    fwrite(&newStudent,sizeof(newStudent),1,forigen);
                    updated = 1;
                    break;
                }
            } else if(strcmp(atributo, "semestre") == 0){
                if(newStudent.semestre == atoi(argv[3])){
                    newStudent.semestre = atoi(argv[4]);
                    fseek(forigen, -1 * sizeof(newStudent),SEEK_CUR);
                    fwrite(&newStudent,sizeof(newStudent),1,forigen);
                    updated = 1;
                    break;
                }
            }else{
                printf("El atributo %s no se encuentra en los registros, pruebe con otro.\n",atributo);
                break;
            }          
        }    
        if(updated){
            printf("Se ha actualizado el registro.\n");
        }else{
            printf("No se ha actulizado ningún registro.\n");
        }
        fclose(forigen);
    }else{
		printf("Error: Ingrese argumentos validos\n");
	}
    return 0;
}