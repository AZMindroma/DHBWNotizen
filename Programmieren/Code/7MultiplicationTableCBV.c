#include<stdio.h>

void upperLayoutGen();
void fillArrayWithValues(int *ptr, int *ptrToA, int *ptrToB);
void printArray(int *ptr);

int main() {
    // Start with 1 times 1
    int a = 1;
    int *ptrToA = NULL;
    int b = 1;
    int *ptrToB = NULL;

    int *ptr = NULL;

    int table[100];
    ptr = table;
    ptrToA = &a;
    ptrToB = &b;

    // DO NOT SEPARATE!
    upperLayoutGen();
    fillArrayWithValues(ptr, ptrToA, ptrToB);
    printArray(ptr);
    // DO NOT SEPARATE!

    return 0;
}

void upperLayoutGen() {
    // First "line" of the table
    int i;

    printf("  * |"); // "Padding" for top-left corner
    for (i = 1; i <= 10; i++) {
        printf("%3d ", i); // Column headers
    }
    printf("\n");

    // Second "line" of the table
    for (i = 1; i <= 45; i++) { // Separator of header and table
        printf("-"); 
    }
    printf("\n");
}

void fillArrayWithValues(int *ptr, int *ptrToA, int *ptrToB) {
    // Fills the array with values
    int i;

    for (i = 0; i < 100; i++) { // Size of the small multiplication table
        *ptr = *ptrToA * *ptrToB;
        if (*ptrToB % 10 != 0) { // If b isn't dividable by 10
            (*ptrToB)++;
        } else { // When b reaches a number dividable by 10...
            *ptrToB = 1;
            (*ptrToA)++;
        }
        ptr++;
    }
}

void printArray(int *ptr) {
    // Writes the values with the necessary labeling of the table
    int i, j;

    for (i = 1; i <= 10; i++) {
        printf("%3d |", i);
        for (j = 1; j <= 10; j++) {
            printf("%3d ", *ptr);
            ptr++;
        }
        printf("\n");
    }
}