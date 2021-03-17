#include <stdio.h> 
#include <stdlib.h>
int main(int numarg, char **argv){
    int total = 0;
    for(int i=1;i<numarg;i++){
		int temp = atoi(argv[i]);
		total += temp;
    }
    printf("%i", total);
    

}
