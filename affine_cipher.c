#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

void affineEncrypt(char text[], int a, int b) {
    int i;
    char ch;
    for(i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        if(isalpha(ch)) {
            if(islower(ch)) {
                text[i] = ((a * (ch - 'a') + b) % 26) + 'a';
            }
            else {
                text[i] = ((a * (ch - 'A') + b) % 26) + 'A';
            }
        }
    }
}

void affineDecrypt(char text[], int a, int b) {
    int i, a_inv;
    char ch;
    a_inv = modInverse(a, 26);   
    for(i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        if(isalpha(ch)) {
            if(islower(ch)) {
                text[i] = ((a_inv * ((ch - 'a' - b + 26) % 26)) % 26) + 'a';
            }
            else {
                text[i] = ((a_inv * ((ch - 'A' - b + 26) % 26)) % 26) + 'A';
            }
        }
    }
}

int main() {
    char text[100];
    int a, b, choice;
    
    printf("Affine Cipher Implementation\n");
    printf("----------------------------\n");
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    
    if(text[strlen(text) - 1] == '\n') {
        text[strlen(text) - 1] = '\0';
    }
    
    do {
        printf("Enter coefficient 'a' (must be coprime to 26): ");
        scanf("%d", &a);
        
        if(gcd(a, 26) != 1) {
            printf("Error: 'a' must be coprime to 26. Try again.\n");
        }
    } while(gcd(a, 26) != 1);
    
    printf("Enter coefficient 'b': ");
    scanf("%d", &b);
    b = b % 26;
    
    printf("\nChoose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);
    
    if(choice == 1) {
        affineEncrypt(text, a, b);
        printf("\nEncrypted text: %s\n", text);
    }
    else if(choice == 2) {
        affineDecrypt(text, a, b);
        printf("\nDecrypted text: %s\n", text);
    }
    else {
        printf("\nInvalid choice!\n");
    }
    return 0;
}
