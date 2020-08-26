/*1. check command line argument for a key
2. make sure all characters are digits
3. convert from string to int
4. ask user for a string (plaintext)
5. iterate over each char of the plaintextt:
5.1. if upper, cypher to upper
5.2. if lower, cypher the lower
5.3. if neither, print as is (e.g. special character)
6. print a newline
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void cipher(string plaintext, int key);

int main(int argc, string argv[])
{
    //check number of arguments in console
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //checks second argument is only digits
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
        }
    }
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    cipher(plaintext, key);

}

//cipher using the provided formula ci = (pi + k) % 26 => Adjusted the modifyer based on upper or lower
void cipher(string plaintext, int key)
{
    for (int i = 0, l = strlen(plaintext); i < l ; i++)
    {
        char c = plaintext[i];
        //for every alphabetic character, cipher
        if (isalpha(c))
        {
            char mod = 'A';
            //adjust calc for lowercase
            if (islower(c))
            {
                mod = 'a';
            }
            //prints each character
            printf("%c", (c - mod + key) % 26 + mod);
        }
        else
        {
            printf("%c", c);
        }
    }
    //print end line
    printf("\n");
}
