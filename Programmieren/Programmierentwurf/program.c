#include<stdio.h>
#include<cjson/cJSON.h>
// External dependency. <ADD PACKAGE NAMES FOR APT>

struct comic {
    int comicID;
    char comicSeries[35+1];
    char comicName[35+1];
    int pages;
    struct comic * prev;
    struct comic * next; 
};

struct comic * ptr = NULL;

// Function prototypes
int write_to_json(char name[], int age, char email[]);

int main() {
    write_to_json("AZ", 18, "mail@azmindroma.de");
}

int write_to_json(char name[], int age, char email[]) {
    cJSON *json = cJSON_CreateObject();
    cJSON_AddStringToObject(json, "name", name);
    cJSON_AddNumberToObject(json, "age", age);
    cJSON_AddStringToObject(json, "email", email);

    char *json_str = cJSON_Print(json);

    FILE *fp = fopen("data.json", "w");
    if (fp == NULL) {
        printf("ERROR");
    }
    fputs(json_str, fp);
    fclose(fp);

    cJSON_free(json_str);
    cJSON_Delete(json);
    return 0;
}