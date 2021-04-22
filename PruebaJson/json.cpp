#include <stdio.h>
#inclide <json-c/json.h>

int main(int argc, char **argv){
    FILE *fp;
    char buffer[1024];

    struct json_object *parsed_json;
    struct json_object *name;
    struct json_object *age;
    struct json_object *friends;

    struct json_object *friend;

    size_t n_friends;
    size_t i;

    fp = fopen("jsonprueba.json", "r");
    fread(buffer, 1024, 1, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "name", &name);
    json_object_object_get_ex(parsed_json, "age", &age);
    json_object_object_get_ex(parsed_json, "friends", &friends);

    printf("name: %s\n", json_object_get_string(name));
    printf("age: %s\n", json_object_get_string(age));


}