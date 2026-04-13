#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);
    int freq[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        freq[s[i] - 'a']++;
        if (freq[s[i] - 'a'] == 2) {
            printf("%c", s[i]);
            return 0;
        }
    }
    printf("No repeated character");
    return 0;
}