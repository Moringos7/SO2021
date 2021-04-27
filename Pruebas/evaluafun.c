#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>

int finish = 0;

void signalHandler(int sig){
  if(sig == 2){
    finish = 1;
    wait(NULL);
  }
}

int main()
{
    signal(2, signalHandler);
    
    int pp2c[2];
    int pc2p[2];

    pipe(pp2c);
    pipe(pc2p);

    switch (fork()) {
        // fork failedn
        case -1:
            printf("Error en Fork");
            break;
        // child
        case 0: 
            close(pp2c[1]);
            dup2(pp2c[0], STDIN_FILENO);
            close(pp2c[0]);
            close(pc2p[0]);
            dup2(pc2p[1], STDOUT_FILENO); 
            close(pc2p[1]);
            execlp("bc", "bc", "-l", NULL);
          break;

        // parent
        default:
            
            close(pp2c[0]);
            close(pc2p[1]);
            FILE *out = NULL;
            FILE *in = NULL;
            while(1){    
                if(finish){
                    break;
                }
                out = fdopen(pp2c[1], "w");
                in = fdopen(pc2p[0], "r");
                int i = 0;
                char ecu[1024];
                char params[1024];
                float init;
                float final;
                float points;
                while(i < 2){
                    if(i == 0){
                        printf("Ingresa Ecuación: \n");
                        scanf("%[^\n]%*c", ecu);   
                    }else{
                        if(finish){
                            break;   
                        }
                        printf("Ingresa Valores [init final points]: \n");
                        scanf( "%f %f %f", &init, &final, &points);
                    }
                    i++;
                }

                if(finish){
                    break;
                }
                float diff = final - init;
                float increment = diff / points;

                char resul[1024]; 
                float total = 0;
                float currentPoint = init;

                while(currentPoint < final){
                    currentPoint += increment;
                    fprintf(out, "x=%f\n", currentPoint);
                    fprintf(out, "%s\n", ecu);
                }
                fflush(out);

                currentPoint = init;
                float temp = 0.0;
                while(currentPoint < final){
                    currentPoint += increment;
                    fscanf(in, "%f", &temp);
                    //printf("-->%f",temp);
                    total += temp;
                }
                float avg = total / points;
                printf("%f\n", avg);
                fflush(in);
                while((fgetc(stdin)) != '\n');
                fflush(stdout);
            }
            
            fclose(out);
            fclose(in);
            wait(NULL);

        break;
    }
    return 0;
}
