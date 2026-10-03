#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter string: ");
    gets(str);
    printf(strcmp(str, strrev(str)) ? "Not a palindrome\n" : "Palindrome\n");
}
