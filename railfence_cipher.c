#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void railFenceEncrypt(char* text, int rails) {
    int len = strlen(text);
    char** fence = (char**)malloc(rails * sizeof(char*));
    for(int i = 0; i < rails; i++) {
        fence[i] = (char*)malloc((len + 1) * sizeof(char));
        for(int j = 0; j < len; j++) {
            fence[i][j] = '\0';
        }
    }
    
    int rail = 0;
    int dir = 0;  
    for(int i = 0; i < len; i++) {
        fence[rail][i] = text[i];
        if(rail == 0) {
            dir = 0;  
        }
        else if(rail == rails - 1) {
            dir = 1;  
        }
        if(dir == 0) {
            rail++;
        }
        else {
            rail--;
        }
    }
    
    printf("Encrypted text: ");
    for(int i = 0; i < rails; i++) {
        for(int j = 0; j < len; j++) {
            if(fence[i][j] != '\0') {
                printf("%c", fence[i][j]);
            }
        }
    }
    printf("\n");
    
    for(int i = 0; i < rails; i++) {
        free(fence[i]);
    }
    free(fence);
}

void railFenceDecrypt(char* text, int rails) {
    int len = strlen(text);
    char** fence = (char**)malloc(rails * sizeof(char*));
    
    for(int i = 0; i < rails; i++) {
        fence[i] = (char*)malloc((len + 1) * sizeof(char));
        for(int j = 0; j < len; j++) {
            fence[i][j] = '\0';
        }
    }
    
    int* counts = (int*)calloc(rails, sizeof(int));
    int rail = 0;
    int dir = 0;  
    
    for(int i = 0; i < len; i++) {
        counts[rail]++;
        if(rail == 0) {
            dir = 0;  
        }
        else if(rail == rails - 1) {
            dir = 1;  
        }
        if(dir == 0) {
            rail++;
        }
        else {
            rail--;
        }
    }
    int index = 0;
    for(int i = 0; i < rails; i++) {
        for(int j = 0; j < counts[i]; j++) {
            fence[i][j] = text[index++];
        }
    }
    rail = 0;
    dir = 0;
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int* positions = (int*)calloc(rails, sizeof(int));
    
    for(int i = 0; i < len; i++) {
        result[i] = fence[rail][positions[rail]++];
        
        if(rail == 0) {
            dir = 0;  
        }
        else if(rail == rails - 1) {
            dir = 1;  
        }
        
        if(dir == 0) {
            rail++;
        }
        else {
            rail--;
        }
    }
    result[len] = '\0';
    printf("Decrypted text: %s\n", result);
    for(int i = 0; i < rails; i++) {
        free(fence[i]);
    }
    free(fence);
    free(counts);
    free(positions);
    free(result);
}

int main() {
    char text[100];
    int rails, choice;
    
    printf("Rail Fence Cipher Implementation\n");
    printf("-------------------------------\n");
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    
    if(text[strlen(text) - 1] == '\n') {
        text[strlen(text) - 1] = '\0';
    }
    
    printf("Enter the number of rails: ");
    scanf("%d", &rails);
    
    if(rails < 2) {
        printf("Number of rails must be at least 2.\n");
        return 1;
    }
    
    printf("\nChoose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);
    
    if(choice == 1) {
        railFenceEncrypt(text, rails);
    }
    else if(choice == 2) {
        railFenceDecrypt(text, rails);
    }
    else {
        printf("\nInvalid choice!\n");
    }
    return 0;
}
