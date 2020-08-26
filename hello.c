#include <stdio.h>
#include<cs50.h>

int main(void)
{
    //ask user for name
    string name = get_string("what is your name? ");
    //print hello + name
    printf("hello, %s\n", name);
}
