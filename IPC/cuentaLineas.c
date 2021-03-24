#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

int main(){
    char c;
    int cont = 0;
    while(read(0,&c,1)){
        if(c == '\n'){
            cont += 1;
        }
    }
    if(c != '\n'){
        cont += 1;
    }
    printf("%d \n",cont);
    return 0;
}