#include<stdio.h>

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

    // First "line" of the table
    printf("  * |"); // "Padding" for top-left corner
    for (int i = 1; i <= 10; i++) {
        printf("%3d ", i); // Column headers
    }
    printf("\n");

    // Second "line" of the table
    for (int i = 1; i <= 45; i++) { // Separator of header and table
        printf("-"); 
    }
    printf("\n");

    // Fills the array with values
    for (size_t i = 0; i < 100; i++) { // Size of the small multiplication table
        *ptr = *ptrToA * *ptrToB;
        if (*ptrToB % 10 != 0) { // If b isn't dividable by 10
            (*ptrToB)++;
        } else { // When b reaches a number dividable by 10...
            *ptrToB = 1;
            (*ptrToA)++;
        }
        ptr++;
    }

    // Jumps back to the beginning of the array to write its values to the table
    ptr = table;

    // Writes the values with the necessary labeling of the table
    for (int i = 1; i <= 10; i++) {
        printf("%3d |", i);
        for (int j = 1; j <= 10; j++) {
            printf("%3d ", *ptr);
            ptr++;
        }
        printf("\n");
    }

    return 0;
}
