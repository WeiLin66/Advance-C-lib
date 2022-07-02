// convert float to str
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

float sqrt_float(uint16_t num, int exp){
    float number = num;

    if(exp == 0)
        return 1;
    else{
        for(int i = 1 ; i < abs(exp) ; i++)
            number *= num;
    }

    if(exp < 0)
        number = 1/number;

    return number;
}

void float_to_string_real_part(float num, char* buffer){ // 浮點數取整
    float value = num;
    int j=0, k=0;
    float inter=1;
    int base=0;
    int quotient;
    
    if(value < 0){
        value *= -1;
        buffer[j++] = '-';
    }
        
    value = floor(value);
    
    printf("value = %f\n", value);
    
    while(floor(value) >= 10){
        value = value / 10;
        base++;
    }
    
    printf("base = %d\n", base);
    
    for(int i=1; i<=base; i++){
        inter *= 10;
    }
    
    printf("inter = %f\n", inter);
    
    value = floor(num);
        
    while(k != base+1){
        quotient = (int)(value/inter);
        printf("quotient = %d\n", quotient);
        buffer[j++] = '0' + quotient;
        value -= quotient*inter;
        inter /= 10;
        k++;
    }
    
    buffer[j] = '\0';
    
    printf("buffer = %s\n", buffer);
}
    
uint32_t float_to_hex(float a){
    float num = a;
    char buffer[40] = {0};
    unsigned int get_hex;
    int i,j=0; 

    get_hex = *(unsigned int*)&a; // hex必須要用unsigned int來取值
    printf("hex: %0x\n", get_hex);
    printf("dec: %0u\n", get_hex);

    for(i = 0; i < 32; i++){
        if(i == 1 || i == 9){
            buffer[j++] = '-';
        }

        if((get_hex >> (32-(i+1)))%2 == 1)
            buffer[j++] = '1';
        else
            buffer[j++] = '0';
    }
    buffer[j] = '\0';
    printf("bin: %s\n", buffer);

    return get_hex;
}

char* hex_to_float_to_str(uint32_t num, int8_t precision){
    int32_t i=0, j=0, exp, m; 
    float real_part;
    float n = 0, value, remain_part;
    char *buffer = (char*)malloc(128);
    char float_to_str[25];

    if((num & 0x80000000) != 0){
        buffer[j++] = '-';
    }

    exp = ((num & 0x7f800000) >> 23) - 127; // exponent
    m = ((num & 0x007fffff));

    for(int32_t i = 1 ; i <= 23 ; i++) // Fraction
        n += (float)((m >> (23 - i))%2) * (1/sqrt_float(2,i)); // double to float

    n++;
    value = n*(sqrt_float(2,exp));

    // Float to string, since no function in C.
    sprintf(float_to_str, "%.0f", value);
    printf("test value: %s\n", float_to_str);
    real_part = atof(float_to_str);
    
    if(real_part > value)
        real_part-=1;
        
    remain_part = value - real_part;
    memset(float_to_str, 0, 25);
    
    for(i = 1 ; i <= precision ; i++)
        remain_part *= 10;

    sprintf(float_to_str,"%.0f", remain_part);
    remain_part = atof(float_to_str);

    if(remain_part < 0) // block '-'
        remain_part *= -1;

    sprintf(buffer+j, "%.0f.%.0f", real_part, remain_part);

    return buffer;
}

int main(){
    float a;
    uint32_t test; 
    char *buffer_p;
    printf("Input a float type number: ");
    scanf("%f", &a);

    test = float_to_hex(a); // float to bin & hex

    buffer_p = hex_to_float_to_str(test, 5); // turn hex to float
    printf("float to string: %s\n", buffer_p);

    return 0;
}
