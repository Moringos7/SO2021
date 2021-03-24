#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

int main(){
    char c;
    char isIn = 0;
    int cont = 0;
    while(read(0,&c,1)){
        isIn = 1;
        if(c == '\n'){
            cont += 1;
        }
    }
    if(isIn){
        if(c != '\n'){
            cont += 1;
        }
    }    
    printf("%d \n",cont);
    return 0;
}