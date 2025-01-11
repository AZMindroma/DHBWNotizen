#include<stdio.h>

int main() {
    // Start with 1 times 1
    int a = 1;
    int b = 1;
    for (size_t i = 1; i < 11; i++)
    {
        printf("%3d", i);
    }
    printf("\n");
    for (size_t i = 0; i < 100; i++) // Size of the small multiplication table
    {
        printf("%3d ", a * b); // Output a times b
        if (b % 10 != 0) { // If b isn't dividable by 10...
            b++; // Increase b to further multiply a with all numbers until the next number dividable by 10 comes.
        } else { // When b reaches a number dividable by 10...
            printf("\n %d |", a); // Make a new line
            b = 1; // Reset b.
            a++; // Increase b
            
        }
    }
}
