#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float index = 0.0588 * (letters / (float)words * 100) - 0.296 * 
(sentences / (float)words * 100) - 15.8;
    int rounded_index = round(index);

    if (rounded_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (rounded_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", rounded_index);
    }
}

int count_letters(string text)
{
    int letters_sum = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters_sum++;
        }
    }
    return letters_sum;
}

int count_words(string text)
{
    int words_sum = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            words_sum++;
        }
    }
    return words_sum;
}

int count_sentences(string text)
{
    int sentences_sum = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == 33 || text[i] == 63 || text[i] == 46)
        {
            sentences_sum++;
        }
    }
    return sentences_sum;
}
