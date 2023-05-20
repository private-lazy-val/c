// Check that a password has at least one lowercase letter, uppercase 
letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, 
lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool isLower = false;
    bool isUpper = false;
    bool isNum = false;
    bool isSymbol = false;
    for (int i = 0, len = strlen(password); i < len; i++)
    {
        if (islower(password[i]))
        {
            isLower = true;
        }
        else if (isupper(password[i]))
        {
            isUpper = true;
        }
        else if (isdigit(password[i]))
        {
            isNum = true;
        }
        else if (ispunct(password[i]))
        {
            isSymbol = true;
        }
    }
    if (isLower == true && isUpper == true && isNum == true && isSymbol == 
true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

