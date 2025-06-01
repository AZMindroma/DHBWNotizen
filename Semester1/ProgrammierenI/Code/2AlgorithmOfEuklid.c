#include<stdio.h>

int main() {
    int a, b;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number:");
    scanf("%d", &b);
    printf("Der groesste gemeinsame Teiler der Zahlen %d und %d ist: ", a, b);

    // Algorithm that we've already done before!
    while (a != b) {
        if (a > b) {
            a = a - b; } 
        else {
            b = b - a;
        }        
    }
    printf("%d\n", a); // Both a and b represent the GCD, so it doesn't matter which one is displayed.
}