#include<bits/stdc++.h>
using namespace std;

// Checking ifa number if prime or composite 

// Naive approacch 
void checkprime(int n)
{
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            count++;
        }
    }
    if(count==2)
    {
        cout<<n<<" is a prime number\n";
    }
    else
    {
        cout<<n<<" is a composite number\n";
    }
    // Time complexity : O(N)
}


// Better approch
void checkprime2(int n)
{
    int count=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(i==sqrt(n))
            {
                count++;
            }
            else
            {
                count = count+2;
            }
        }
    }
    if(count==2)
    {
        cout<<n<<" is a prime number\n";
    }
    else{
        cout<<n<<" is a composite number\n";
    }
    // Time complexity : O(sqrt(N))
}

int main()
{

    // Calling the functions 
    checkprime(12);
    checkprime2(12);

    checkprime(3);
    checkprime2(3);
    return 0;
}