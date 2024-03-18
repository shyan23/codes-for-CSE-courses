#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_WORDS 1000

typedef struct words {
    char word[1000];
    int freq;
} words;

int main() {
    words record[MAX_WORDS];
    int count = 0;

    FILE* file = fopen("in.txt", "r");
    if (file == NULL) {
        printf("File cannot be opened.\n");
        exit(1);
    }

    char storage[1000];
    fgets(storage, sizeof(storage), file);

    char* str = strtok(storage, " \n");
    while (str != NULL && count < MAX_WORDS) {
        int flag = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(str, record[i].word) == 0) {
                record[i].freq++;
                flag = 1;
                break;
            }
        }

        if (!flag) {
            strcpy(record[count].word, str);
            record[count].freq = 1;
            count++;
        }

        str = strtok(NULL, " \n");
    }

    fclose(file);

    int max = record[0].freq;
    int ind = 0;

    for (int i = 1; i < count; i++) {
        if (max < record[i].freq) {
            max = record[i].freq;
            ind = i;
        }
    }

    printf("Most frequent word: %s\n", record[ind].word);

    return 0;
}
