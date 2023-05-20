// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Enter one word you want to convert\n");
        return 1;
    }

    string word = argv[1];
    replace(word);
    printf("Converted word: %s\n", word);
    return 0;
}

string replace(string word)
{
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        switch (word[i])
        {
        case 'a':
        case 'A':
            word[i] = '6';
            break;
        case 'e':
        case 'E':
            word[i] = '3';
            break;
        case 'i':
        case 'I':
            word[i] = '1';
            break;
        case 'o':
        case 'O':
            word[i] = '0';
            break;
        default:
            break;
        }
    }
    return word;
}

