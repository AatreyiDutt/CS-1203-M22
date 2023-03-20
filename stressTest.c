#include <stdio.h>
#include <stdlib.h>

void main(){
    double x = 10;
    int iter = 26;
    for (int i=1; i<iter; i++){
        if(i==23)printf("double starts messing up here:\n");    // based on observation
        printf("10^%d = %f\n", i, x);
        x = x*10;
    }
}


