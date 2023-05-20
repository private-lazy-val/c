#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string make_cipher(string key, string text);

int main(int argc, string argv[])
{
    // check if two arguments are passed and there are exactly 26 letters 
in the key
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    string key = argv[1];
    int key_length = strlen(key);
    if (key_length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // check if the key contains only alphabetic letters and each letter 
occurs exactly once
    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }
        for (int j = i + 1; j < key_length; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }

    printf("plaintext: ");
    string plaintext = get_string("");

    string ciphertext = make_cipher(key, plaintext);
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

string make_cipher(string key, string plaintext)
{
    string ciphertext = plaintext;
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = isupper(plaintext[i]) ? 
toupper(key[plaintext[i] - base]) : tolower(key[plaintext[i] - base]);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    return ciphertext;
}
