#include <stdio.h>
#include <string.h>

int is_prime(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main(void) {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    
    for (int i = 0; i < strlen(str); i++) {
        if (is_prime(i)) {
            if (i % 10 == 3) {
                printf("$");
            } else {
                printf("%c", str[i]);
            }
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}