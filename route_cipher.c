#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fillBlock(char **block, int numRows, int numCols, char *message) {
    int k = 0;
    int messageLen = strlen(message);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (k < messageLen) {
                block[i][j] = message[k++];
            } else {
                block[i][j] = 'X'; 
            }
        }
    }
}

void encryptBlockSpiral(char **block, int numRows, int numCols, char *encrypted) {
    int k = 0;
    int rowStart = 0, rowEnd = numRows - 1;
    int colStart = 0, colEnd = numCols - 1;
    
    while (rowStart <= rowEnd && colStart <= colEnd) {
        for (int j = colStart; j <= colEnd; j++) {
            encrypted[k++] = block[rowStart][j];
        }
        rowStart++;
        for (int i = rowStart; i <= rowEnd; i++) {
            encrypted[k++] = block[i][colEnd];
        }
        colEnd--;
        if (rowStart <= rowEnd) {
            for (int j = colEnd; j >= colStart; j--) {
                encrypted[k++] = block[rowEnd][j];
            }
            rowEnd--;
        }
        if (colStart <= colEnd) {
            for (int i = rowEnd; i >= rowStart; i--) {
                encrypted[k++] = block[i][colStart];
            }
            colStart++;
        }
    }
    encrypted[k] = '\0';
}

void decryptBlockSpiral(char *encrypted, char **block, int numRows, int numCols) {
    int k = 0;
    int rowStart = 0, rowEnd = numRows - 1;
    int colStart = 0, colEnd = numCols - 1;
    
    while (rowStart <= rowEnd && colStart <= colEnd) {
        for (int j = colStart; j <= colEnd; j++) {
            block[rowStart][j] = encrypted[k++];
        }
        rowStart++;
        for (int i = rowStart; i <= rowEnd; i++) {
            block[i][colEnd] = encrypted[k++];
        }
        colEnd--;
        if (rowStart <= rowEnd) {
            for (int j = colEnd; j >= colStart; j--) {
                block[rowEnd][j] = encrypted[k++];
            }
            rowEnd--;
        }
        if (colStart <= colEnd) {
            for (int i = rowEnd; i >= rowStart; i--) {
                block[i][colStart] = encrypted[k++];
            }
            colStart++;
        }
    }
}

void readBlock(char **block, int numRows, int numCols, char *decrypted) {
    int k = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            decrypted[k++] = block[i][j];
        }
    }
    decrypted[k] = '\0';
}

void printBlock(char **block, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%c ", block[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numRows, numCols;
    char message[100], encrypted[100], decrypted[100];
    
    printf("Spiral Route Cipher Implementation\n");
    printf("---------------------------------\n");
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }
    
    printf("Enter number of rows: ");
    scanf("%d", &numRows);
    printf("Enter number of columns: ");
    scanf("%d", &numCols);

    char **block = (char **)malloc(numRows * sizeof(char *));
    for (int i = 0; i < numRows; i++) {
        block[i] = (char *)malloc(numCols * sizeof(char));
    }
    fillBlock(block, numRows, numCols, message);
    printf("\nMessage in grid (row-major order):\n");
    printBlock(block, numRows, numCols);
    
    encryptBlockSpiral(block, numRows, numCols, encrypted);
    printf("\nEncrypted message (spiral route): %s\n", encrypted);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            block[i][j] = ' ';
        }
    }
    decryptBlockSpiral(encrypted, block, numRows, numCols);
    
    printf("\nEncrypted message in grid (spiral route):\n");
    printBlock(block, numRows, numCols);
    readBlock(block, numRows, numCols, decrypted);
    printf("\nDecrypted message: %s\n", decrypted);
    for (int i = 0; i < numRows; i++) {
        free(block[i]);
    }
    free(block);
    return 0;
}
