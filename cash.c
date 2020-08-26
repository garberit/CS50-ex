#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float input;
    int q = 25;
    int d = 10;
    int n = 5;
    int p = 1;

    do
    {
        input = get_float("Change Owed: ");
    }
    while (input < 0);

    int cents = round(input * 100);
    int counter = 0;

    while(cents >= q)
    {
        cents -= q;
        counter ++;
    }

    while (cents >= d)
    {
        cents -= d;
        counter ++;
    }

    while (cents >= n)
    {
        cents -= n;
        counter ++;
    }

    while (cents >= p)
    {
        cents -= p;
        counter ++;
    }

    printf("%i\n", counter);

}
