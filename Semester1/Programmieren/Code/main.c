/* file: main.c */
#include<stdio.h>

int main() {
    char scannedChar;
    float var1 = 15 % 4;
    float var2 = 15 / 2.0;
    float var3 = 3 + 5 % 4;
    float var4 = 3 * 7 % 4;

    printf("Hello World!\n\n");
    printf("Please enter a character: ");
    scannedChar = getchar();
    printf("You entered %c as character\n", scannedChar);

    printf("15 % 4 = %3.2f\n", var1);
    printf("15 / 2.0 = %f\n", var2);
    printf("3 + 5 % 4 = %f\n", var3);
    printf("3 * 7 % 4 = %f\n", var4);

    int res, a, b, c;
    int y=5;
    printf ("Value of 7||(y=0): %d\n", 7||(y=0));
    printf ("Value of y: %d\n", y);
    a = b = c = 0;
    res = ++a || ++b && ++c;
    printf ("\nres = %d, a = %d, ", res, a);
    printf ("b = %d, c = %d\n", b, c);
    a = b = c = 0;
    res = ++a && ++b || ++c;
    printf ("\nres = %d, a = %d, ", res, a);
    printf ("b = %d, c = %d\n", b, c);
    return (0);
}