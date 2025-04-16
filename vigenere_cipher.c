#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenereEncrypt(char text[], char key[]) {
    int i, j = 0;
    char c;
    for(i = 0; text[i] != '\0'; i++) {
        c = text[i];      
        if(isalpha(c)) {
            if(islower(c)) {
                text[i] = ((c - 'a' + (tolower(key[j]) - 'a')) % 26) + 'a';
            }
            else {
                text[i] = ((c - 'A' + (toupper(key[j]) - 'A')) % 26) + 'A';
            }
            j = (j + 1) % strlen(key);
        }
    }
}

void vigenereDecrypt(char text[], char key[]) {
    int i, j = 0;
    char c;
    
    for(i = 0; text[i] != '\0'; i++) {
        c = text[i];        
        if(isalpha(c)) {
            if(islower(c)) {
                text[i] = ((c - 'a' - (tolower(key[j]) - 'a') + 26) % 26) + 'a';
            }
            else {
                text[i] = ((c - 'A' - (toupper(key[j]) - 'A') + 26) % 26) + 'A';
            }
            j = (j + 1) % strlen(key);
        }
    }
}

int main() {
    char text[100], key[20];
    int choice;
    
    printf("Vigenere Cipher Implementation\n");
    printf("----------------------------\n");
    printf("Enter the text (up to 100 characters): ");
    fgets(text, sizeof(text), stdin);
    
    if(text[strlen(text) - 1] == '\n') {
        text[strlen(text) - 1] = '\0';
    }    
    printf("Enter the key (up to 20 characters): ");
    fgets(key, sizeof(key), stdin);
    
    if(key[strlen(key) - 1] == '\n') {
        key[strlen(key) - 1] = '\0';
    }
    
    printf("\nChoose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);
    
    if(choice == 1) {
        vigenereEncrypt(text, key);
        printf("\nEncrypted text: %s\n", text);
    }
    else if(choice == 2) {
        vigenereDecrypt(text, key);
        printf("\nDecrypted text: %s\n", text);
    }
    else {
        printf("\nInvalid choice!\n");
    }    
    return 0;
}
