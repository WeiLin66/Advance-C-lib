#include "JSON_bsp.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

bool check_json_parse(cJSON **p_root_parser, int *p_json_ary_size, uint8_t *p_paylod){

	if(p_paylod == NULL){
		return false;
	}else{
		*p_root_parser = cJSON_Parse((const char*)p_paylod);
		*p_json_ary_size = cJSON_GetArraySize(*p_root_parser);
	}

    if( (*p_root_parser == NULL) || (*p_json_ary_size <= 0) ){
        return false;
    }

	return true;
}

int main(){
    cJSON* root_ptr = NULL;
    int numbers=0;
    char test_str[] = "[{\"id\":\"FC0_43001\",\"value\":10},{\"id\":\"FC0_43002\",\"value\":10},{\"id\":\"FC0_43003\",\"value\":10}]";

    if(check_json_parse(&root_ptr, &numbers, (uint8_t*)test_str)){
        printf("numbers: %d\n", numbers);
	}else{
        printf("failed!\n");
    }

    return 0;
}