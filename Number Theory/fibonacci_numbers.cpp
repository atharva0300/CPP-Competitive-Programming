#include<bits/stdc++.h>
using namespace std;


/* 
    We know Fibonacci number, Fn = Fn-1 + Fn-2. 
    First few Fibonacci numbers are 0, 1, 1, 2, 5 3, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, …. . 
*/
/* 
    1. Pattern in Last digits of Fibonacci numbers : 
    Last digits of first few Fibonacci Numbers are : 
    0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, ... 
*/

/* 
    2. Factors of Fibonacci number : On careful observation, we can observe the following thing :

    Every 3-rd Fibonacci number is a multiple of 2
    Every 4-th Fibonacci number is a multiple of 3
    Every 5-th Fibonacci number is a multiple of 5
    Every 6-th Fibonacci number is a multiple of 8
*/
#define max 100
int main()
{
    long long int arr[MAX];
    arr[0] = 0;
    arr[1] = 0;
    int i=0;
    // storing fibonacci numbers
    for(int i=2;i<max;i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
    // traversing through store numbers 
    for(int i=1;i<max;i++)
    {
        // since the first 2 number are 0 and 1 
        // so, if any 2 consecutive number encounter 0 and 1 
        // at their unit place, then it clearly means that 
        // number is repeating/since we just have to find 
        // the sum of previous 2 numbers
        if((arr[i]%10==0) && (arr[i+1]%10==1))
        {
            break;
        }
    }
    cout<<"Sequence is repeating after index : "<<i<<"\n";

    long long int arr[MAX] , index1[MAX] , index2[MAX];
    long long int index3[MAX] ,index4[MAX];

    // storing fibonacci numbers 
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2;i<MAX;i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }

    // c1 keeps track of number of index of number
    // divisible by 2 and others c2 ,c3 and c4 for 
    // 3,5 and 8
    int c1 = 0;
    int c2 = 0;
    int c3 =0;
    int c4=0;

    //separating fibonacci number into their 
    // respective array 
    for(int i=0;i<MAX;i++)
    {
        if(arr[i]%2==0)
        {
            index1[c1++]=i;
        }
        if(arr[i]%3==0)
        {
            index2[c2++] = i;
        }
        if(arr[i]%5==0)
        {
            index3[c3++] =i;
        }
        if(arr[i]%8==0)
        {
            index4[c4++] = i;
        }
    }

    // printing index arrays 
    cout<<"\nIndex of Fibonacci numbers divisible by 2 : \n";
    for(int i=0;i<c1;i++)
    {
        cout<<index1[i];
        cout<<" ";
    }

    cout<<"\nIndex of Fibonaci number divisible by 3 : \n";
    for(int i=0;i<c2;i++)
    {
        cout<<index2[i]<<" ";
    }

    cout<<"\nIndex of Fibonacci numbers divisible by 5 : \n";
    for(int i=0;i<c3;i++)
    {
        cout<<index3[i]<<" ";
    }

    cout<<"\nIndex of Fibonacci numbers divisible by 8 : \n";
    for(int i=0;i<c4;i++)
    {
        cout<<index4[i]<<" ";
    }
    cout<<"\n";

    /* 
        3. Fibonacci number with index number factor : We have some Fibonacci 
        number like F(1) = 1 which is divisible by 1, F(5) = 5 which is divisible 
        by 5, F(12) = 144 which is divisible by 12, F(24) = 46368 which is 
        divisible by 24, F(25) = 75025 which is divisible by 25. This type of 
        index number follow a certain pattern. First, let’s keep a look on those 
        index number : 
        1, 5, 12, 24, 25, 36, 48, 60, 72, 84, 96, 108, 120, 125, 132, ….. 

        On observing it, this series is made up of every number that 
        is multiple of 12 as well as all the number that satisfies the 
        condition of pow(5, k), where k = 0, 1, 2, 3, 4, 5, 6, 7, …….
    */

   // storing Fibonacci numbers
    long long int arr[MAX];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < MAX; i++)
        arr[i] = arr[i-1] + arr[i-2];
 
    cout<<"Fibonacci numbers divisible by "
        "their indexes are :\n";
    for (int i = 1; i < MAX; i++)
        if (arr[i] % i == 0)
            cout<<"  "<< i;
    
    cout<<"\n";

    /*
        4. Value of f(n-1)*f(n+1) – f(n)*f(n) is (-1)n. 
        Please refer Cassini’s Identity for details.
    */
    return 0;
}