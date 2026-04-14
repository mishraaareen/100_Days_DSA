#include <stdio.h>
#include <string.h>

char firstNonRepeating(char *s) {
    int count[26] = {0};
    int i;

    for (i = 0; s[i]; i++)
        count[s[i] - 'a']++;

    for (i = 0; s[i]; i++)
        if (count[s[i] - 'a'] == 1)
            return s[i];

    return '$';
}

int main() {
    char s[1000];
    scanf("%s", s);
    printf("%c", firstNonRepeating(s));
    return 0;
}