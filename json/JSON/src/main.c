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
    cJSON* cjson_test = cJSON_CreateObject(); // create dummy head
    cJSON* cjson_delivery = cJSON_CreateObject();
    cJSON* cjson_material = cJSON_CreateArray();

    cJSON_AddStringToObject(cjson_test, "Object", "Table"); // add string type key-value pair
    cJSON_AddNumberToObject(cjson_test,"Width",800); // add number type key-value pair
    cJSON_AddNumberToObject(cjson_test,"Length",600);

    /* add JSON object as a key-value pair */
    cJSON_AddStringToObject(cjson_delivery, "County", "New Taipei City");
    cJSON_AddNumberToObject(cjson_delivery,"Postal code",234);
    cJSON_AddItemToObject(cjson_test, "Address", cjson_delivery);

    /* add array object as a key-value pair */
    cJSON_AddItemToArray(cjson_material, cJSON_CreateString("Wood"));
    cJSON_AddItemToArray(cjson_material, cJSON_CreateString("Metal"));
    cJSON_AddItemToArray(cjson_material, cJSON_CreateString("Plastic"));
    cJSON_AddItemToObject(cjson_test, "Material", cjson_material);

    cJSON_AddTrueToObject(cjson_test, "Qualified");

    printf("%s\n", cJSON_Print(cjson_test)); // print JSON


    return 0;
}