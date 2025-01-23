#include<stdio.h>
#include<string.h>

struct filecard {
    long long id;
    char firstName[20+1];
    char lastName[25+1];
    char street[20+1];
    int zipCode;
    char city[20+1];
};

void makeFilecard(struct filecard *ptr, long long id, char firstName[], char lastName[], char street[], int zipCode, char city[]);
void outputFilecard(struct filecard *ptr);

int main() {
    struct filecard person[10];
    struct filecard *ptr, *ptr2;
    
    ptr = person;
    makeFilecard(ptr, 83117115115121, "Furkan", "Toptas", "Altschauerberg 8", 91448, "Emskirchen");
    outputFilecard(ptr);

    ptr2 = ptr;
    ptr++;
    makeFilecard(ptr, 43875643875459, "Max", "Mustermann", "Musterstrasse", 80085, "Zweihuegelstadt");
    outputFilecard(ptr);
    outputFilecard(ptr2);
}

void makeFilecard(struct filecard *ptr, long long id, char firstName[], char lastName[], char street[], int zipCode, char city[]) {
    ptr->id = id;
    strcpy(ptr->firstName, firstName);
    strcpy(ptr->lastName, lastName);
    strcpy(ptr->street, street);
    ptr->zipCode = zipCode;
    strcpy(ptr->city, city);
}

void outputFilecard(struct filecard *ptr) {
    printf("ID: %lu\n", ptr->id);
    printf("First name: %s\n", ptr->firstName);
    printf("Last name: %s\n", ptr->lastName);
    printf("Street: %s\n", ptr->street);
    printf("Zip code: %d\n", ptr->zipCode);
    printf("City: %s\n", ptr->city);
    printf("\n");
}