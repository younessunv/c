/*
#include <stdio.h>
#include <string.h>

void rm_spaces_punctuation(char *str, char *result);
void Palindrome_Checker(char *chng_str, int len);

int main()
{
    char str[50], chng_str[50];

    printf("insert a string: ");
    fgets(str, 50, stdin);

    rm_spaces_punctuation(str, chng_str);
    printf("%s", chng_str);

    int len = strlen(chng_str);
    Palindrome_Checker(chng_str, len);

    return 0;
}

void rm_spaces_punctuation(char *str, char *result)
{
    char punctuation[] = {',', '.', '?', '!', '"', '\'', ':', ';', '-', '_', '(', ')', '{', '}', '[', ']', '~', '#', '<', '>', '^', '`', ' '};
    int j = 0, len = strlen(str);
    int size = sizeof(punctuation) / sizeof(punctuation[0]);

    for (int i = 0; i < len; i++)
    {
        int is_punctuation = 0;
        for (int k = 0; k < size; k++)
        {
            if (str[i] == punctuation[k])
            {
                is_punctuation = 1;
                break;
            }
        }
        if (!is_punctuation)
        {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
}

void Palindrome_Checker(char *chng_str, int len)
{
    int j = 0;
    char rev_str[len];

    for (int i = len - 1; i >= 0; i--)
    {
        rev_str[j++] = chng_str[i];
    }
    rev_str[j] = '\0';

    if (strcmp(chng_str, rev_str) == 0)
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }
}
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if a character is a letter (ignores spaces and punctuation)
int isLetter(char ch) {
    return isalpha(ch);
}

// Function to convert a character to lowercase
char toLower(char ch) {
    return tolower(ch);
}

// Function to check if a given string is a palindrome
int isPalindrome(const char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        // Ignore spaces and punctuation from the start
        while (start < length && !isLetter(str[start])) {
            start++;
        }

        // Ignore spaces and punctuation from the end
        while (end >= 0 && !isLetter(str[end])) {
            end--;
        }

        // If characters are not the same, the string is not a palindrome
        if (start < length && end >= 0 && toLower(str[start]) != toLower(str[end])) {
            return 0; // Not a palindrome
        }

        start++;
        end--;
    }

    return 1; // Palindrome
}

int main() {
    char input[100];

    printf("Enter a string to check if it's a palindrome: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character if present
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    if (isPalindrome(input)) {
        printf("The entered string is a palindrome.\n");
    } else {
        printf("The entered string is not a palindrome.\n");
    }

    return 0;
}

