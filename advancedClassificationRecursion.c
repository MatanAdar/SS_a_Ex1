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

int isPalindromeReverse(int num , int ReverseNum)
{
    if(NumberLength(num)==0){
        return ReverseNum;
    }
    ReverseNum=ReverseNum*10+num%10;
    return isPalindromeReverse(num/10, ReverseNum);
}

int isPalindrome(int OriginalNumber)
{   
    int ReverseOriginalNumber=isPalindromeReverse(OriginalNumber,0);

    return(ReverseOriginalNumber==OriginalNumber);
   
}

int isArmstongLength(int num, int length)
{   
    int changeOriginalNumber=num;
    if(changeOriginalNumber==0){
        return 0;
    }
    return pow(changeOriginalNumber%10,length)+isArmstongLength(changeOriginalNumber/10,length);
}


int isArmstrong(int OriginalNumber)
{
    int sum=isArmstongLength(OriginalNumber,NumberLength(OriginalNumber));

    if(sum==OriginalNumber)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}