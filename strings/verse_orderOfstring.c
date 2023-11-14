#include <stdio.h>
#include <string.h>

void reverseWords(char str[], int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() {
    int i, j = 0;
    char str[33];

    fputs("Insert a string and I will reverse it for you: ", stdout);
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);

    reverseWords(str, 0, len - 2);


    for (i = 0; i < len; i++) {
        if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n') {
            reverseWords(str, j, i - 1);
            j = i + 1;
        }
    }

    fputs(str, stdout);

    return 0;
}
