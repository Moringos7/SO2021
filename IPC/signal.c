#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int finish = 0;

void signalHandler(int sig){
  if(sig == 10){
	finish = 1;
  }else{
	 printf("Recibi señal %d\n", sig);
  }
}

int main(){
  signal(10, signalHandler);
  signal(2, signalHandler);
  while(!finish){
    printf("Trabajando\n");
    sleep(1);
  }
  printf("Ya voy a terminar \n");
  return 0;
}