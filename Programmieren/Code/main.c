/* file: main.c */
#include<stdio.h>

int main() {
    printf("Hello World!\n\n");
    printf("Please enter a character: ");
    char scannedChar = getchar();
    printf("You entered %c as character\n", scannedChar);
}