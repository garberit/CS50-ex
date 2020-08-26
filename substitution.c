#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    //check number of arguments in console
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    //check length of key is 26 characters
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }


    //checks for alphabetic chars
    for (int i = 0, l = strlen(key); i < l; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must be alphabetic.\n");
            return 1;
        }
    }

    //checks for duplicate chars
    for (int i = 0, l = strlen(key); i < l; i++)
    {
        int counter = 0;
        for (int j = 0, len = strlen(key); j < len; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                counter ++;
                if (counter > 1)
                {
                    printf("Invalid key provided. Must have no duplicates!\n");
                    return 1;
                }
            }
        }

    }

    //ask for plaintext
    string plaintext = get_string("plaintext: ");

    //finds difference
    for (int i = 'A'; i < 'Z'; i++)
    {
        key[i - 'A'] = toupper(key[i - 'A']) - i;
    }

    printf("ciphertext: ");

    for (int i = 0, l = strlen(plaintext); i < l; i++)
    {
        //finds the diff between plaintext and key equivalent
        if (isalpha(plaintext[i]))
        {
            plaintext[i] = plaintext[i] + key[plaintext[i] - (isupper(plaintext[i]) ? 'A' : 'a')];
        }
        printf("%c", plaintext[i]); //print each of the characters
    }
    printf("\n");
}
