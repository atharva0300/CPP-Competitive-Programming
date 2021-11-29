/* 
    Binary numbers and Bits Basics 
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    /* 
        and = & 
        or - |
        xor - ^ 
        left shift  : << 
            example - 3<<1
                    Means that perform left binary shifting, to the binary number of 3 
                    110 becomes 11000  ( 2 )
                    3>>1 
                    Means sthat perform right bianry shoftig , to the binary number 3 
                    110 becomes 11 ( 1 )
    */
    cout<<INT_MAX<<"\n";
    /*
        1<<0 = 1
        1<<1 = 10 =2
        1<<2 = 100 = 4
            = 1000 = 8
        
        general formula : 1<<m = 2^m
        */
    int a = (1LL<<32) -1;
    cout<<a<<"\n";
    // outputs -1 , because, the number got overflowed 

    int b = (1LL<<31)-1;
    cout<<b<<"\n";
    // works and is equal to INT_MAX

    // the reason ,that integer alue, of 32 bits is not stored 
    // is because,it is a signed integer 
    // lets use unsogned integer 

    unsigned int c = (1LL<<32) -1;
    cout<<c<<"\n";
    // works , with no overflow 
    

    // the 1st bit of the 32 bits is reserved for sign 
        // 1 - negative( - )
        // 0 - positive( + )
    // so the remaining, 31 bits is stored
    // but using unsigned, the 1st bit of the 32 bits, is utilized 
    // for storing a number, and not the sign ( so that one bits also gets counted )






    return 0;
}