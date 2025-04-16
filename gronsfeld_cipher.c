#include <stdio.h>
#include <string.h>
#include <ctype.h>

void gronsfeldEncrypt(char text[], char key[]) {
    int i, j = 0;
    int keyLen = strlen(key);
    char c;
    
    for(i = 0; text[i] != '\0'; i++) {
        c = text[i];
        if(isalpha(c)) {
            int shift = key[j] - '0';
            
            if(islower(c)) {
                text[i] = ((c - 'a' + shift) % 26) + 'a';
            }
            else {
                text[i] = ((c - 'A' + shift) % 26) + 'A';
            }
            
            j = (j + 1) % keyLen;
        }
    }
}

void gronsfeldDecrypt(char text[], char key[]) {
    int i, j = 0;
    int keyLen = strlen(key);
    char c;
    for(i = 0; text[i] != '\0'; i++) {
        c = text[i];
        if(isalpha(c)) {
            int shift = key[j] - '0';
            
            if(islower(c)) {
                text[i] = ((c - 'a' - shift + 26) % 26) + 'a';
            }
            else {
                text[i] = ((c - 'A' - shift + 26) % 26) + 'A';
            }
            
            j = (j + 1) % keyLen;
        }
    }
}

int main() {
    char text[100], key[20];
    int choice;
    
    printf("Gronsfeld Cipher Implementation\n");
    printf("-------------------------------\n");
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    
    if(text[strlen(text) - 1] == '\n') {
        text[strlen(text) - 1] = '\0';
    }
    
    printf("Enter the numeric key (0-9 digits only): ");
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
        gronsfeldEncrypt(text, key);
        printf("\nEncrypted text: %s\n", text);
    }
    else if(choice == 2) {
        gronsfeldDecrypt(text, key);
        printf("\nDecrypted text: %s\n", text);
    }
    else {
        printf("\nInvalid choice!\n");
    }
    
    return 0;
}
