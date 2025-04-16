#include <stdio.h>
#include <string.h>
#include <ctype.h>

void atbash(char text[]) {
    int i;
    char ch;
    for(i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        if(isalpha(ch)) {
            if(islower(ch)) {
                text[i] = 'z' - (ch - 'a');
            }
            else {
                text[i] = 'Z' - (ch - 'A');
            }
        }
    }
}

int main() {
    char text[100];
    int choice;
    
    printf("Atbash Cipher Implementation\n");
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
    
    if(choice == 1 || choice == 2) {
        atbash(text);
        if(choice == 1) {
            printf("\nEncrypted text: %s\n", text);
        } else {
            printf("\nDecrypted text: %s\n", text);
        }
    }
    else {
        printf("\nInvalid choice!\n");
    }
    return 0;
}
