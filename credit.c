#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardNum = get_long("Card number: ");
    long firstNum = cardNum;
    int cardLength = 1;
    while (firstNum >= 10)
    {
        firstNum /= 10;
        cardLength += 1;
    }
    printf("%i\n", cardLength);

    long firstTwoNums = cardNum;
    while (firstTwoNums >= 100)
    {
        firstTwoNums /= 10;
    }

    string cardType;
    if (firstNum == 4 && (cardLength == 13 || cardLength == 16))
    {
        cardType = "VISA";
    }
    else if ((firstTwoNums == 34 || firstTwoNums == 37) && cardLength == 
15)
    {
        cardType = "AMEX";
    }
    else if ((firstTwoNums >= 51 && firstTwoNums <= 55) && cardLength == 
16)
    {
        cardType = "MASTERCARD";
    }
    else {
        printf("INVALID\n");
        return 0;
    }

    int sum = 0;
    long slicedCardNum = cardNum / 10;
    while(slicedCardNum > 0)
    {
        int doubledNum = (slicedCardNum % 10) * 2;
        sum += doubledNum % 10 + doubledNum / 10;
        slicedCardNum /= 100;
    }

    while(cardNum > 0)
    {
        sum += cardNum % 10;
        cardNum /= 100;
    }

    if(sum % 10 != 0) {
        printf("INVALID\n");
        return 0;
    }

    printf("%s\n", cardType);

}
