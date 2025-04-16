#include <stdio.h>
#include <string.h>
#include <ctype.h>

void beaufortCipher(char text[], char key[]) {
    int i, j = 0;
    int keyLen = strlen(key);
    char c;   
    for(i = 0; text[i] != '\0'; i++) {
        c = text[i];
        if(isalpha(c)) {
            char keyChar = toupper(key[j % keyLen]);            
            if(islower(c)) {
                text[i] = 'a' + ((keyChar - toupper(c) + 26) % 26);
            }
            else {
                text[i] = 'A' + ((keyChar - c + 26) % 26);
            }
            j++;
        }
    }
}

int main() {
    char text[100], key[20];
    int choice;
    
    printf("Beaufort Cipher Implementation\n");
    printf("-----------------------------\n");    
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    
    if(text[strlen(text) - 1] == '\n') {
        text[strlen(text) - 1] = '\0';
    }    
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    
    if(key[strlen(key) - 1] == '\n') {
        key[strlen(key) - 1] = '\0';
    }    
    for(int i = 0; key[i] != '\0'; i++) {
        if(islower(key[i])) {
            key[i] = toupper(key[i]);
        }
    }
    
    printf("\nChoose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);
    beaufortCipher(text, key);
    
    if(choice == 1) {
        printf("\nEncrypted text: %s\n", text);
    }
    else if(choice == 2) {
        printf("\nDecrypted text: %s\n", text);
    }
    else {
        printf("\nInvalid choice!\n");
    }
    
    return 0;
}
