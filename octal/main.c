#include <stdio.h>
#include <stdlib.h>


//calculate an octal number into decimal
//Oktal: Basis 8: 0-7
// does NOT check if the number is in the allowed area (e.g. for octal, assumes all digits are 0-7)
int convertIntoDecimal (int startingBase, int number);
int getLastDigit (int number);
int getDigitSum (int number);
int calculatePower (int base, int power);

int main()
{
    int input = 0;
    int output = 0;
    int inputBase = 8;
    int digitSum = 0;
    printf(": ");
    scanf("%d", &input);
    output = convertIntoDecimal (inputBase, input);
    printf("dec.: %d\n", output);

    digitSum = getDigitSum(output);
    printf("ZS: %d", digitSum);
    return 0;
}

int convertIntoDecimal (int startingBase, int number)
{
    int lastDigit = 0;
    int power = 0;  //we go from right to left, so the power (of the exponential equation) increases, starting from 0
    int result = 0;
    //we take the last digit, calculate the equivalent in decimal, remove the last digit...
    //... and start over (removing the next digit) until we go through all the digits
    //which means, the number becomes 0
    while (number!=0)
    {
        lastDigit = getLastDigit(number);
        result = result + lastDigit * calculatePower(startingBase, power); //we continuously add to the result
        power++;    //increase power by 1, for the next digit
        number = number/10; //remove last digit
    }

    return result;
}


int getLastDigit (int number)
{
    int lastDigit = 0;
    lastDigit = number % 10;
    return lastDigit;
}

int getDigitSum (int number)
{
    int lastDigit = 0;
    int digitSum = 0;
    while (number != 0) //we add to the digitSum, and remove the last digit, until we run out of digits
                        //which means, number becomes 0
    {
        lastDigit = getLastDigit(number);
        digitSum = digitSum + lastDigit;
        number = number/10; //remove last digit
    }
    return digitSum;
}

int calculatePower (int base, int power)
{
    int result = 1;
    for (int i=0; i<power; i++)
    {
        result = result * base;
    }
    return result;
}
