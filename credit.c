#include <stdio.h>
#include <cs50.h>
#include <math.h>

bool check_card(long long input);
int get_length(long long n);
bool checksum(long long n);
void print_cc_brand(long long n);

int main(void)
{
    long long input;

    //get user input, keep asking until valid long
    do
    {
        input = get_long_long("Number: ");
    }
    while (input < 0);

    //call validity check function
    if (check_card(input))
    {
        print_cc_brand(input);
    }
    else
    {
        printf("Invalid\n");
    }
}

//checks if card is valid
bool check_card(long long n)
{
    int card_length = get_length(n);
    return (card_length == 13 || card_length == 15 || card_length == 16) && checksum(n);
}

//gets length of number
int get_length(long long n)
{
    int l;
    for (l = 0; n != 0; n /= 10)
    {
        l++;
    }
    return l;
}

//calculates the sum of odds and evens per Luhn’s algorithm
bool checksum(long long n)
{
    int sum = 0;
    for (int i = 0; n != 0; i++, n /= 10)
    {
        //even number adding up
        if (i % 2 == 0)
        {
            sum += n % 10;
        }
        //odd numbers multiplying by 2, adding individual digits of 2 digit numbers, summing all up
        else
        {
            int num = 2 * (n % 10);
            sum += (num / 10) + (num % 10);
        }
    }
    return (sum % 10) == 0;
}

//checks preconsidtions for card brands
void print_cc_brand(long long n)
{
    if ((n >= 34e13 && n < 35e13) || (n >= 37e13 && n < 38e13)) //amex preconditions
    {
        printf("AMEX\n");
    }
    else if (n >= 51e14 && n < 56e14) //mastercard preconditions
    {
        printf("MASTERCARD\n");
    }
    else if ((n >= 4e12 && n < 5e12) || (n >= 4e15 && n < 5e15)) //visa preconditions
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}
