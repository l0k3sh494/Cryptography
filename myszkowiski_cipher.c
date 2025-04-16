#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void generateKeySequence(char *keyword, int *keySequence) {
    int len = strlen(keyword);
    char sortedKey[len + 1];
    strcpy(sortedKey, keyword);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (sortedKey[i] > sortedKey[j]) {
                char temp = sortedKey[i];
                sortedKey[i] = sortedKey[j];
                sortedKey[j] = temp;
            }
        }
    }
    int value = 1;
    for (int i = 0; i < len; i++) {
        if (i > 0 && sortedKey[i] != sortedKey[i-1]) {
            value++;
        }
        for (int j = 0; j < len; j++) {
            if (keyword[j] == sortedKey[i]) {
                keySequence[j] = value;
                sortedKey[i] = '0'; 
                break;
            }
        }
    }
}

void myszkowskiEncrypt(char *plaintext, char *keyword, char *ciphertext) {
    int ptLen = strlen(plaintext);
    int keyLen = strlen(keyword);
    int keySequence[keyLen];
    
    generateKeySequence(keyword, keySequence);
    int numRows = (ptLen + keyLen - 1) / keyLen;
    char **grid = (char **)malloc(numRows * sizeof(char *));
    for (int i = 0; i < numRows; i++) {
        grid[i] = (char *)malloc(keyLen * sizeof(char));
    }
    int k = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < keyLen; j++) {
            if (k < ptLen) {
                grid[i][j] = plaintext[k++];
            } else {
                grid[i][j] = 'X'; 
            }
        }
    }
    k = 0;
    int maxValue = 0;
    for (int i = 0; i < keyLen; i++) {
        if (keySequence[i] > maxValue) {
            maxValue = keySequence[i];
        }
    }
    
    for (int value = 1; value <= maxValue; value++) {
        int columns[keyLen];
        int colCount = 0;
        
        for (int j = 0; j < keyLen; j++) {
            if (keySequence[j] == value) {
                columns[colCount++] = j;
            }
        }
        
        if (colCount == 1) {
            int col = columns[0];
            for (int row = 0; row < numRows; row++) {
                ciphertext[k++] = grid[row][col];
            }
        } 
        else if (colCount > 1) {
            for (int row = 0; row < numRows; row++) {
                for (int c = 0; c < colCount; c++) {
                    ciphertext[k++] = grid[row][columns[c]];
                }
            }
        }
    }
    
    ciphertext[k] = '\0';
    for (int i = 0; i < numRows; i++) {
        free(grid[i]);
    }
    free(grid);
}

void myszkowskiDecrypt(char *ciphertext, char *keyword, char *plaintext) {
    int ctLen = strlen(ciphertext);
    int keyLen = strlen(keyword);
    int keySequence[keyLen];
    
    generateKeySequence(keyword, keySequence);
    int numRows = (ctLen + keyLen - 1) / keyLen;
    char **grid = (char **)malloc(numRows * sizeof(char *));
    for (int i = 0; i < numRows; i++) {
        grid[i] = (char *)malloc(keyLen * sizeof(char));
        for (int j = 0; j < keyLen; j++) {
            grid[i][j] = ' ';
        }
    }
    int k = 0;
    int maxValue = 0;
    for (int i = 0; i < keyLen; i++) {
        if (keySequence[i] > maxValue) {
            maxValue = keySequence[i];
        }
    }
    
    for (int value = 1; value <= maxValue; value++) {
        int columns[keyLen];
        int colCount = 0;
        
        for (int j = 0; j < keyLen; j++) {
            if (keySequence[j] == value) {
                columns[colCount++] = j;
            }
        }
        if (colCount == 1) {
            int col = columns[0];
            for (int row = 0; row < numRows && k < ctLen; row++) {
                grid[row][col] = ciphertext[k++];
            }
        }
        else if (colCount > 1) {
            for (int row = 0; row < numRows && k < ctLen; row++) {
                for (int c = 0; c < colCount && k < ctLen; c++) {
                    grid[row][columns[c]] = ciphertext[k++];
                }
            }
        }
    }
    k = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < keyLen; j++) {
            plaintext[k++] = grid[i][j];
        }
    }
    
    plaintext[k] = '\0';
    for (int i = 0; i < numRows; i++) {
        free(grid[i]);
    }
    free(grid);
}

int main() {
    char plaintext[1000], keyword[100], ciphertext[1000], decrypted[1000];
    int choice;
    
    printf("Myszkowski Transposition Cipher Implementation\n");
    printf("--------------------------------------------\n");
    printf("Enter the text: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    if (plaintext[strlen(plaintext) - 1] == '\n') {
        plaintext[strlen(plaintext) - 1] = '\0';
    }
    
    printf("Enter the keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    if (keyword[strlen(keyword) - 1] == '\n') {
        keyword[strlen(keyword) - 1] = '\0';
    }
    for (int i = 0; i < strlen(keyword); i++) {
        keyword[i] = toupper(keyword[i]);
    }
    
    printf("\nChoose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        myszkowskiEncrypt(plaintext, keyword, ciphertext);
        printf("\nEncrypted text: %s\n", ciphertext);
    }
    else if (choice == 2) {
        myszkowskiDecrypt(plaintext, keyword, decrypted);
        printf("\nDecrypted text: %s\n", decrypted);
    }
    else {
        printf("\nInvalid choice!\n");
    }
    
    return 0;
}
