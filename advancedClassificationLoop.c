#include "NumClass.h"
#include <math.h>

int isPalindrome(int x)
{
    int OriginalNumber=x;
    int LastNum=0;
    int FirstNum=0;

    while(OriginalNumber>0)
    {
        LastNum=OriginalNumber%10;
        FirstNum=OriginalNumber/(pow(10,NumberLength(OriginalNumber)-1));

        if(LastNum!=FirstNum){
            return 0;
        }

        OriginalNumber=OriginalNumber%(int)(pow(10,NumberLength(OriginalNumber)-1));
        OriginalNumber=OriginalNumber/10;
        
    }
    return 1;
}

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