#include<stdio.h>
#define INTERESTRATE 1.034 // Put this as symbolic variable so it can be changed more flexibly :)

int main() {
    float capital;
    
    printf("Input base capital (in EUR) to create an interest table from: "); // Allows for custom input
    scanf("%f", &capital); // Saved into the address of capital. We'll probably learn later on why

    printf("Interest table for a base capital of %.2f EUR\nThe following table shows the capital at year-end\n\n", capital);

    for (size_t i = 1; i < 11; i++) // Saving variables for the year displays by making the numbers count exactly as needed
    {
        capital = capital * INTERESTRATE; // Increasing of capital
        printf("year: %2.d \t capital: %.2f EUR\n", i, capital); // \t adds a tab
    }
    
}