#include <stdio.h>
#include <string.h>
#include <ctype.h>

void augustEncrypt(char text[]) {
    int i;
    char ch;
    
    for(i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        if(isalpha(ch)) {
            if(islower(ch)) {
                ch = (ch - 'a' + 1) % 26 + 'a';
            }
            else {
                ch = (ch - 'A' + 1) % 26 + 'A';
            }            
            text[i] = ch;
        }
    }
}

void augustDecrypt(char text[]) {
    int i;
    char ch;
    for(i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        if(isalpha(ch)) {
            if(islower(ch)) {
                ch = (ch - 'a' - 1 + 26) % 26 + 'a';
            }
            else {
                ch = (ch - 'A' - 1 + 26) % 26 + 'A';
            }
            text[i] = ch;
        }
    }
}

int main() {
    char text[100];
    int choice;
    
    printf("August Cipher Implementation\n");
    printf("----------------------------\n");
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    if(text[strlen(text) - 1] == '\n') {
        text[strlen(text) - 1] = '\0';
    }
    
    printf("\nChoose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);
    
    if(choice == 1) {
        augustEncrypt(text);
        printf("\nEncrypted text: %s\n", text);
    }
    else if(choice == 2) {
        augustDecrypt(text);
        printf("\nDecrypted text: %s\n", text);
    }
    else {
        printf("\nInvalid choice!\n");
    }
    return 0;
}
