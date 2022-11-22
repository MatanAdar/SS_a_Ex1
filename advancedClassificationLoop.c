#include "NumClass.h"
#include <math.h>

int NumberLength(int x)
{
    int length=0;
    while(x!=0)
    {
        length++;
        x=x/10;
    }
    return length;
}

int isPalindrome(int OriginalNumber)
{
    int changeOriginalNumber=OriginalNumber;
    int reverseOriginalNumber=0;
   while(NumberLength(changeOriginalNumber)>0)
   {
        reverseOriginalNumber=reverseOriginalNumber*10;
        reverseOriginalNumber+=changeOriginalNumber%10;
        changeOriginalNumber=changeOriginalNumber/10;
   }

   return (reverseOriginalNumber==OriginalNumber);
  
}


int isArmstrong(int OriginalNumber)
{
    int sum=0;
    int ChangeOriginalNumber=OriginalNumber;
    while(ChangeOriginalNumber>0)
    {
        sum+=pow(ChangeOriginalNumber%10,NumberLength(OriginalNumber));
        ChangeOriginalNumber=ChangeOriginalNumber/10;
    }

    if(sum==OriginalNumber)
    {
        return 1;
    }
    else
    {
    return 0;
    }
}