#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 1000
#define MAX_NGRAMS 1000

typedef struct {
    char ngram[10];
    int count;
} NGramEntry;

char* preprocessText(char* text) {
    int i, j = 0;
    char* result = (char*)malloc(strlen(text) + 1);
    for(i = 0; text[i] != '\0'; i++) {
        if(isalpha(text[i])) {
            result[j++] = toupper(text[i]);
        }
    }
    result[j] = '\0';
    return result;
}

void countNgrams(char* text, int n) {
    int i, j, found;
    int textLen = strlen(text);
    int ngramCount = 0;
    NGramEntry ngrams[MAX_NGRAMS];
    
    if(textLen < n) {
        printf("Text is too short for %d-grams.\n", n);
        return;
    }
    
    for(i = 0; i <= textLen - n; i++) {
        char currentNgram[10] = {0};
        strncpy(currentNgram, text + i, n);
        found = 0;
        for(j = 0; j < ngramCount; j++) {
            if(strcmp(ngrams[j].ngram, currentNgram) == 0) {
                ngrams[j].count++;
                found = 1;
                break;
            }
        }
        if(!found && ngramCount < MAX_NGRAMS) {
            strcpy(ngrams[ngramCount].ngram, currentNgram);
            ngrams[ngramCount].count = 1;
            ngramCount++;
        }
    }
    printf("\n--- %d-gram Frequencies ---\n", n);
    for(i = 0; i < ngramCount; i++) {
        printf("%s : %d\n", ngrams[i].ngram, ngrams[i].count);
    }
}

int main() {
    char text[MAX_TEXT];
    char* processedText;
    int choice;
    
    printf("N-gram Analysis Implementation\n");
    printf("-----------------------------\n");
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    if(text[strlen(text) - 1] == '\n') {
        text[strlen(text) - 1] = '\0';
    }
    processedText = preprocessText(text);
    
    printf("\nChoose N-gram type:\n");
    printf("1. Unigram (1-gram)\n");
    printf("2. Bigram (2-gram)\n");
    printf("3. Trigram (3-gram)\n");
    printf("4. Tetragram (4-gram)\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);   
    if(choice >= 1 && choice <= 4) {
        countNgrams(processedText, choice);
    }
    else {
        printf("\nInvalid choice!\n");
    }
    free(processedText);
    return 0;
}
