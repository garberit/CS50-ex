#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Backwards Output: ");
    for (int i = strlen(s) -1; i >= 0; i--)
    {
        printf("%c", tolower(s[i]));
    }
    printf("\n");
}
