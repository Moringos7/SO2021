#include <stdio.h>
#include <stdlib.h>

int main(){
    char str[80], ch; //str = &str[0]
    int dato;
    float valor;
    //scanf("%s %i %f", str, &dato, &valor);
    scanf("%s",str);
    while((fgetc(stdin)) != '\n');
    /*printf("%f \n",valor);
    printf("%c",ch);*/
    printf("\n");
    fflush(stdout);
    return 0;
}
