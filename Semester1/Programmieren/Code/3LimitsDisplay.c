#include<stdio.h>
#include<limits.h>

int main() {
    printf("Minimum value a char can hold: %d\n", CHAR_MIN);
    printf("Maximum value a char can hold: %d\n", CHAR_MAX);

    printf("Minimum value a signed int can hold: %d\n", INT_MIN);
    printf("Maximum value a signed int can hold: %d\n", INT_MAX);

    printf("Minimum value a long can hold: %lld\n", LONG_MIN);
    printf("Maximum value a long can hold: %lld\n", LONG_MAX);
}
