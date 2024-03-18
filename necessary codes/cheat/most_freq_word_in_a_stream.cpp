#include <iostream>
#include <cstring>

using namespace std;

typedef struct words {
    char word[1000];
    int freq;

    words() {
        strcpy(word, " ");
        freq = 0;
    }
} words;

int main() {
    words record[1000];
    int n;
    cin >> n;
    cin.ignore(); // Consume the newline character after reading an integer

    int count = 0;
    while (n--) {
        char p[1000];
        fgets(p, 1000, stdin);
        char* s = strtok(p, " \n");
        while (s != NULL) {
            int flag = 0;
            for (int i = 0; i < 1000; i++) {
                if (strcmp(s, record[i].word) == 0) {
                    record[i].freq++;
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                strcpy(record[count].word, s);
                record[count].freq = 1;
                count++;
            }
            s = strtok(NULL, " \n");
        }
    }

    int ind = 0;
    int max = record[0].freq;
    for (int i = 1; i < count; i++) {
        if (max < record[i].freq) {
            max = record[i].freq;
            ind = i;
        }
    }

    cout << record[ind].word << endl;

    return 0;
}
