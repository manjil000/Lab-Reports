#include <stdio.h>

int main() {
    char str[100], result[100];
    int i, j = 0;

    printf("Enter a string: ");
    fgets(str, 100, stdin);  // Read input string

    // Remove the newline character if present
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    // Process the string and remove vowels
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
            str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            result[j++] = str[i];  // Copy consonants and other characters
        }
    }
    
    result[j] = '\0';  // Add null terminator to make it a valid string

    printf("String after removing vowels: %s\n", result);

    return 0;
}
