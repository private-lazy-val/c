#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    submit50 cs50/problems/2023/x/mario/morewhile (height < 1 || height > 
8);

    for (int levels = 1; levels <= height; levels++)
    {
        for (int i = 0; i < height - levels; i++)
        {
            printf(" ");
        }

        for (int j = 0; j < levels; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int j = 0; j < levels; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
