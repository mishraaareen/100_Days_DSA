#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    scanf("%d", &n);
    char **votes = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        votes[i] = malloc(101);
        scanf("%s", votes[i]);
    }

    qsort(votes, n, sizeof(char *), cmp);

    int maxCount = 1, count = 1;
    char *winner = votes[0];

    for (int i = 1; i < n; i++) {
        if (strcmp(votes[i], votes[i - 1]) == 0) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                winner = votes[i - 1];
            }
            count = 1;
        }
    }

    if (count > maxCount) {
        winner = votes[n - 1];
    }

    printf("%s\n", winner);

    for (int i = 0; i < n; i++) free(votes[i]);
    free(votes);
    return 0;
}