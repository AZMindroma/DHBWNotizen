#include<stdio.h>

int main() {
    unsigned char input;

    printf("Input a character to find out its ASCII value: ");
    input = getchar();
    printf("The ASCII value for the character \"%c\" is: %d\n", input, input);
}