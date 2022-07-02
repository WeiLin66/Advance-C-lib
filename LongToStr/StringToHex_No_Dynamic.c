#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define SOCKET_BUFFER_SIZE 1024

uint8_t SocketBufTemp[SOCKET_BUFFER_SIZE]={0}; 

uint8_t* StringToHex(uint8_t* str, uint32_t len){
    char tmp[16];
	uint8_t* buffer = SocketBufTemp;
	
	if(strlen((char*)buffer)!=0){
	    strcpy((char*)buffer, "");
	}

    for(int i=0; i<len; i++){
        sprintf(tmp, "%02x", str[i]);
        strcat((char*)buffer, tmp);
        memset(tmp, '0', 16);
    }
    
    return buffer;
}

int main(){
    StringToHex("apple", 5);
    printf("%s\n", SocketBufTemp);
    
    StringToHex("orange", 6);
    printf("%s\n", SocketBufTemp);
    
    return 0;
}
