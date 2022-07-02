/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdint.h>
#include <malloc.h>

uint8_t* StringToHex(char* str, uint32_t len){
    uint8_t* buffer = (uint8_t*)realloc(0,256);
    char tmp[16];

    for(int i=0; i<len; i+=2){
        sprintf(tmp, "%02x", str[i]);
        strcat((char*)buffer, tmp);
        memset(tmp, '0', 16);
    }
    
    return buffer;
}

uint32_t resolver(uint32_t num){
    uint32_t resolve=num;
    if(resolve >= 97 && resolve <= 122){
        resolve -= 32;
    }
    
    if(resolve >=65 && resolve <= 90)
        resolve -= 55;
    else
        resolve -= '0';
    
    return resolve;
}

uint8_t* StringHexToString(uint8_t* str, int len){
    uint32_t tmp_h, tmp_l, count=0;
    uint8_t* buffer = (uint8_t*)malloc(len/2+1);
    uint8_t cChar;
    for(int i=0; i<len; i+=2){
        tmp_h = resolver(str[i]);
        tmp_l = resolver(str[i+1]);
        
        cChar = (tmp_h << 4) + (tmp_l);
        buffer[count++] = cChar;
    }
    buffer[count] = '\0';
    
    return buffer;
}

int main()
{
    return 0;
}
