#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int length;
    do
    {
        length = get_int("Length: ");
    } while (length < 1);

    int twice[length];

    twice[0] = 1;
    printf("%i\n", twice[0]);
    for (int i = 1; i < length; i++)
    {
        twice[i] = twice[i - 1] * 2;
        printf("%i\n", twice[i]);
    }
}
