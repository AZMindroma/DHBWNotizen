/* file: main.c */
#include<stdio.h>

int main() {
    char scannedChar;

    printf("Hello World!\n\n");
    printf("Please enter a character: ");
    scannedChar = getchar();
    printf("You entered %c as character\n", scannedChar);
}