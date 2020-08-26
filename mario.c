#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //create height, row, column and space integers
    int h, r, c, s;

    do
    {
        //ask user for height
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    for(r = 0; r < h; r++)
        {
            for (s = 0; s < h - r - 1; s++)
            {
                printf(" ");
            }
            for (c = 0; c <= r; c++)
            {
                printf("#");
            }
            printf("  ");
            for (c = 0; c <= r; c++)
            {
                printf("#");
            }
            printf("\n");
        }
}
