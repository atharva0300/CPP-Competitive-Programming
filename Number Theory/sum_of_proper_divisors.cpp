#include<bits/stdc++.h>
using namespace std;


/* 
Input : num = 10
Output: 8
// proper divisors 1 + 2 + 5 = 8 

Input : num = 36
Output: 55
// proper divisors 1 + 2 + 3 + 4 + 6 + 9 + 12 + 18 = 55 
*/

/* 
    This problem has very simple solution, we all know that for 
    any number ‘num’ all its divisors are always less than and equal to 
    ‘num/2’ and all prime factors are always less than and equal to sqrt(num). 
    So we iterate through ‘i’ till i<=sqrt(num) and for any ‘i’ if it divides 
    ‘num’ , then we get two divisors ‘i’ and ‘num/i’ , continuously add these 
    divisors but for some numbers divisors ‘i’ and ‘num/i’ will same in this 
    case just add only one divisor , e.g; num=36 so for i=6 we will get (num/i)=6 , 
    that’s why we will at 6 in the summation only once. Finally we add one as one is
    divisor of all natural numbers.
*/


// Function to calcualte sum of all proper divisors 
// num -> given natural number 
int divSum(int num)
{
    // Final result of summation of divisors 
    int result = 0;
    if(num==1)  // there will be no divisors
    if(num==1)
    {
        return result;
    }
    // find all divisors which divides 'num'
    for(int i=2;i<=sqrt(num);i++)
    {
        // if 'i' is divisors of 'num'
        if(num%i==0)
        {
            // if both divisors are same then add 
            // it only once else add both 
            if(i==(num/i))
            {
                result = result + i;
            }
            else{
                result = result + ( i + num/i);
            }
        }
    }

    // add 1 to the result as 1 is also a divisor 
    return (result +1);
}


int main()
{
    int num = 36;
    cout<<divSum(num)<<"\n";
    return 0;
}