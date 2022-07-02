#include <stdio.h>

int main(){
    float a = 0;
    while(1){
        a += 0.02;
        printf("%f\n", a);
        if(a == 4)
            break;
    }

    return 0;
}