void int64_t_to_string(int64_t val, char* buffer){
    int i=0;
    int64_t remain;
    int intergrade = 0;
    int64_t base = 1;
    int64_t quotient = val;

    
    if(val == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        
        return;
    }
    
    if(val < 0){
        quotient = -quotient;
        buffer[i++] = '-';
    }
    
    remain = quotient;
    
    while(remain){
        intergrade++;
        remain  /= 10;
    }
    
    for(int j=1; j<intergrade; j++)
        base *= 10;
    

    while(base != 0){
        buffer[i++] = "0123456789abcdef"[quotient / base];
        quotient %= base;
        base /= 10;
    }

    buffer[i] = '\0';
}

void uint64_t_to_string(uint64_t val, char* buffer){
    int i=0;
    uint64_t remain;
    int intergrade = 0;
    uint64_t base = 1;
    uint64_t quotient = val;

    
    if(val == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        
        return;
    }
    
    remain = quotient;
    
    while(remain){
        intergrade++;
        remain  /= 10;
    }
    
    for(int j=1; j<intergrade; j++)
        base *= 10;
    

    while(base != 0){
        buffer[i++] = "0123456789abcdef"[quotient / base];
        quotient %= base;
        base /= 10;
    }

    buffer[i] = '\0';
}
