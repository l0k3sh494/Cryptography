#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N 2  

int determinant(int key[N][N]) {
    return (key[0][0] * key[1][1] - key[0][1] * key[1][0]);
}
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;  
}

void adjoint(int key[N][N], int adj[N][N]) {
    adj[0][0] = key[1][1];
    adj[0][1] = -key[0][1];
    adj[1][0] = -key[1][0];
    adj[1][1] = key[0][0];   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adj[i][j] < 0) {
                adj[i][j] = (adj[i][j] % 26 + 26) % 26;
            }
        }
    }
}

int inverse(int key[N][N], int inv[N][N]) {
    int det = determinant(key);
    det = (det % 26 + 26) % 26; 
    int detInv = modInverse(det, 26);
    if (detInv == -1) {
        printf("The key matrix is not invertible. Choose another key.\n");
        return 0;
    }
    int adj[N][N];
    adjoint(key, adj);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inv[i][j] = (adj[i][j] * detInv) % 26;
        }
    }
    return 1;
}

void encrypt(char *message, int key[N][N]) {
    int len = strlen(message);
    if (len % N != 0) {
        message[len] = 'X';
        message[len + 1] = '\0';
        len++;
    }
    printf("Encrypted message: ");
    
    for (int i = 0; i < len; i += N) {
        int p[N];
        for (int j = 0; j < N; j++) {
            p[j] = toupper(message[i + j]) - 'A';
        }
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += key[j][k] * p[k];
            }
            printf("%c", (sum % 26) + 'A');
        }
    }
    printf("\n");
}

void decrypt(char *message, int key[N][N]) {
    int len = strlen(message);
    int inv[N][N];
    
    if (!inverse(key, inv)) {
        return;
    }
    printf("Decrypted message: ");
    for (int i = 0; i < len; i += N) {
        int c[N];
        for (int j = 0; j < N; j++) {
            c[j] = toupper(message[i + j]) - 'A';
        }
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += inv[j][k] * c[k];
            }
            printf("%c", (sum % 26) + 'A');
        }
    }
    printf("\n");
}

int main() {
    int key[N][N];
    char message[100];
    int choice;
    
    printf("Hill Cipher Implementation\n");
    printf("-------------------------\n");
    printf("Enter the key matrix (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &key[i][j]);
        }
    }    
    int det = determinant(key);
    if (det == 0 || modInverse(det % 26, 26) == -1) {
        printf("The key matrix is not invertible. Choose another key.\n");
        return 1;
    }
    getchar(); 
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    
    printf("\nChoose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        encrypt(message, key);
    }
    else if (choice == 2) {
        decrypt(message, key);
    }
    else {
        printf("\nInvalid choice!\n");
    }
    return 0;
}
