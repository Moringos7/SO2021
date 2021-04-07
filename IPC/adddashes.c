#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

int main(int numarg, char **argv){
    // tuberia
    int fd[2];
    pipe(fd);
    int pid = fork();
    if(pid == 0){
        //Proceso hijo
        close(fd[1]);
        dup2(fd[0],STDIN_FILENO);
        execl("/usr/bin/tr", "tr", "' '", "-",NULL);
    }else{
        //Proceso Padre
        close(fd[0]);
        dup2(fd[1],STDOUT_FILENO);
        execl("/usr/bin/cat", "cat", NULL);
    }
    return 0;
}