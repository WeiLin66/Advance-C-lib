#include "JSON_bsp.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(){
    printf("constitution of JSON data format begin ===>\n\n");

    cJSON* cjson_test = cJSON_CreateObject(); // create dummy head
    cJSON* cjson_delivery = cJSON_CreateObject();
    cJSON* cjson_material = cJSON_CreateArray();


    /**
     *  creating JSON data format
     */
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

    printf("%s\n\n", cJSON_Print(cjson_test)); // print JSON
    cJSON_Delete(cjson_test); // deallocate cjson_test
    printf("constitution of JSON data format end ===>\n\n");

    /**
     * Parsing JSON content
     */
    printf("Parsing JSON data begin ===>\n\n");

    cJSON* cjson_test_p = NULL;
    cJSON* cjson_test_name = NULL;
    cJSON* cjson_test_age = NULL;
    cJSON* cjson_test_weight = NULL;

    char cjson_test_message[] = "{                              \
                    \"name\": \"Zach Lin\",                     \
                    \"age\": 27,                                \
                    \"weight\": 72.87,                          \
                    \"address\":                                \
                    {                                           \
                        \"country\": \"Taiwan\",                \
                        \"city-code\": 234                      \
                    },                                          \
                    \"skill\": [\"c\", \"Java\", \"OS\"],       \
                    \"student\": false                          \
                }";

    if((cjson_test_p = cJSON_Parse(cjson_test_message)) == NULL){
        printf("wrong JSON format\n");
        return -1;
    }

    printf("%s\n\n", cJSON_Print(cjson_test_p));
    printf("Total Items: %d\n\n", cJSON_GetArraySize(cjson_test_p));

    /* parsing single JSON data */
    cjson_test_name = cJSON_GetObjectItem(cjson_test_p, "name");
    cjson_test_age = cJSON_GetObjectItem(cjson_test_p, "age");
    cjson_test_weight = cJSON_GetObjectItem(cjson_test_p, "weight");

    printf("name: %s\n", cjson_test_name->valuestring);
    printf("age: %d\n", cjson_test_age->valueint);
    printf("weight: %f\n\n", cjson_test_weight->valuedouble);

    /* parsing nested JSON data */
    cJSON* cjson_test_address = NULL;
    cJSON* cjson_test_address_country = NULL;
    cJSON* cjson_test_address_city_code = NULL;

    cjson_test_address = cJSON_GetObjectItem(cjson_test_p, "address");
    cjson_test_address_country = cJSON_GetObjectItem(cjson_test_address, "country");
    cjson_test_address_city_code = cJSON_GetObjectItem(cjson_test_address, "city-code");

    printf("country: %s\n", cjson_test_address_country->valuestring);
    printf("city-code: %d\n\n", cjson_test_address_city_code->valueint);

    /* parsing array */
    cJSON* cjson_test_skill = NULL;
    cJSON* cjson_test_skill_item = NULL;
    int array_len = 0;

    cjson_test_skill = cJSON_GetObjectItem(cjson_test_p, "skill");
    array_len = cJSON_GetArraySize(cjson_test_skill);

    for(int i=0; i<array_len; i++){
        cjson_test_skill_item = cJSON_GetArrayItem(cjson_test_skill, i);
        printf("skill[%d]: %s\n", i, cjson_test_skill_item->valuestring);
    }

    /* boolean type*/
    cJSON* cjson_test_student = cJSON_GetObjectItem(cjson_test_p, "student");

    if(cjson_test_student->valueint){
        printf("\nstudent: true\n");
    }else{
        printf("\nstudent: false\n");
    }

    cJSON_Delete(cjson_test_p);
    printf("Parsing JSON data end ===>\n\n");

    return 0;
}