#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cjson/cJSON.h>
// External dependency. <ADD PACKAGE NAMES FOR APT>
// Requires adding an extra argument to gcc: -lcjson
// gcc program.c -lcjson -o program

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
int write_to_json(struct comic * ptr);
struct comic * add_element (struct comic * ptr);
struct comic * create_new_list (struct comic * ptr);
int fill_element (struct comic * ptr);

int main() {
    ptr = create_new_list(ptr);
    write_to_json(ptr);
    ptr = create_new_list(ptr);
}

int write_to_json(struct comic * ptr) {
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "comicID", ptr->comicID);
    cJSON_AddStringToObject(json, "comicSeries", ptr->comicSeries);
    cJSON_AddStringToObject(json, "comicName", ptr->comicName);
    cJSON_AddNumberToObject(json, "pages", ptr->pages);

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

struct comic * create_new_list (struct comic * ptr) {
    if (ptr) {
        printf ("A list already exists.\n");
    } 
    else {
        ptr = (struct comic *) malloc (sizeof (struct comic));
        printf("Allocating... ");
        ptr->prev = NULL;
        printf("Setting prev to NULL... ");
        ptr->next = NULL;
        printf("Setting next to NULL... ");
        fill_element (ptr);
    }
    return (ptr);
}

int fill_element (struct comic * ptr) {
    /*clear_screen ();
    printf (" Please enter the following data:\n\n");
    printf (" PNR: ");
    scanf ("%d", &ptr->pnr);
    printf (" Name: ");
    scanf ("%s", ptr->name);
    press_enter ();
    return (0);*/
    ptr->comicID = 1;
    strcpy(ptr->comicName, "SLIS");
    strcpy(ptr->comicSeries, "Lalal");
    ptr->pages = 5;
    printf("Filled...");
}

struct comic * add_element (struct comic * ptr) {
    if (!ptr) {
        printf ("No list does exist.\n");
    } 
    else {
        while (ptr->next) ptr=ptr->next;
        ptr->next = (struct comic *) malloc (sizeof (struct comic));
        ptr->next->prev = ptr;
        ptr = ptr->next;
        ptr->next = NULL;
        //fill_element (ptr);
    }
    return (ptr);
}