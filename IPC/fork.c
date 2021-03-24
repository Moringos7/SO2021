#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void signalHandler(int sig){
  printf("Mi hijo %d terminó \n",wait(NULL));
}

int main(){
    signal(17, signalHandler);
    int pid = fork();
    if(pid == 0){
        //Proceso hijo
        printf("Soy Proceso hijo\n");
    }else{
        printf("Soy Proceso padre y mi hijo es %d\n",pid);
        /*Sincrono
        wait(NULL); 
        printf("Mi hijo %d terminó \n",wait(NULL));*/
        while(1){
            printf("Trabajando\n");
            sleep(1);
        }

    }
    printf("Terminado\n");
    return 0;
}
//Señal 17 sigChild