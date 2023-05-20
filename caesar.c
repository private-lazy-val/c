#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string argv);
string rotate(string element, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

   if (only_digits(argv[1]) == false)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[1]);

    printf("Plaintext: ");
    string plaintext = get_string("");

    string ciphertext = rotate(plaintext, key);
    printf("Ciphertext: %s\n", ciphertext);
}

bool only_digits(string argv)
{
    for (int i = 0, len = strlen(argv); i < len; i++)
    {
       if (!isdigit(argv[i]))
       {
        return false;
       }
    }
    return true;
}


string rotate(string element, int key)
{
    for (int i = 0, len = strlen(element); i < len; i++)
    {
        if (isalpha(element[i]))
        {
            char base = isupper(element[i]) ? 'A' : 'a';
            element[i] = (element[i] - base + key) % 26 + base;
        }
    }
    return element;
}
