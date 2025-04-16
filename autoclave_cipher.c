#include <stdio.h>
#include <string.h>
#include <ctype.h>

void autokeyEncrypt(char text[], char key[]) {
    int i;
    int keyLen = strlen(key);
    char fullKey[1000];
    strcpy(fullKey, key);
    
    for(i = 0; text[i] != '\0'; i++) {
        if(i >= keyLen && isalpha(text[i - keyLen])) {
            fullKey[i] = toupper(text[i - keyLen]);
        }
        if(isalpha(text[i])) {
            char keyChar = fullKey[i];
            
            if(islower(text[i])) {
                text[i] = ((text[i] - 'a' + (keyChar - 'A')) % 26) + 'a';
            }
            else {
                text[i] = ((text[i] - 'A' + (keyChar - 'A')) % 26) + 'A';
            }
        }
    }
}

void autokeyDecrypt(char text[], char key[]) {
    int i;
    int keyLen = strlen(key);
    char fullKey[1000];
    char decrypted[1000];
    strcpy(fullKey, key);
    
    for(i = 0; text[i] != '\0'; i++) {
        if(isalpha(text[i])) {
            char keyChar = fullKey[i];
            if(islower(text[i])) {
                decrypted[i] = ((text[i] - 'a' - (keyChar - 'A') + 26) % 26) + 'a';
            }
            else {
                decrypted[i] = ((text[i] - 'A' - (keyChar - 'A') + 26) % 26) + 'A';
            }
            
            if(i >= keyLen) {
                fullKey[i + keyLen] = toupper(decrypted[i]);
            }
        }
        else {
            decrypted[i] = text[i];
        }
    }
    decrypted[i] = '\0';
    strcpy(text, decrypted);
}

int main() {
    char text[1000], key[100];
    int choice;
    
    printf("Autokey Cipher Implementation\n");
    printf("----------------------------\n");
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    
    if(text[strlen(text) - 1] == '\n') {
        text[strlen(text) - 1] = '\0';
    }
    
    printf("Enter the primer key: ");
    fgets(key, sizeof(key), stdin);
    
    if(key[strlen(key) - 1] == '\n') {
        key[strlen(key) - 1] = '\0';
    }
    for(int i = 0; key[i] != '\0'; i++) {
        key[i] = toupper(key[i]);
    }
    
    printf("\nChoose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);
    
    if(choice == 1) {
        autokeyEncrypt(text, key);
        printf("\nEncrypted text: %s\n", text);
    }
    else if(choice == 2) {
        autokeyDecrypt(text, key);
        printf("\nDecrypted text: %s\n", text);
    }
    else {
        printf("\nInvalid choice!\n");
    }
    
    return 0;
}
