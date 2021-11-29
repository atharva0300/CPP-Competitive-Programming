/* 
    playing with bits 
*/

#include<bits/stdc++.h>
using namespace std;


/* 
    the least significant bit, is the right most bit of the binary representation
    example - 
            1     0     1     1    1    1
            6th   5th   4th   3rd  2nd  1st 
            the 1st bit, is the least significant bit
            */
    
    /* 
        if the bit is '1' then the bit is considered, as set, else unset 

        exmaple - 5 = 1  0  1
                checking if the first bit is set or not 

                we will find the binary, number whose 1st bit is set, andd the rest other 
                // bits are unset 
                // and performing, AND operation 

                // if the AND result comes out to be '0' , theen the 1st bit is unset 
                // if the AND result comes out to be '1' , then the 1t bit is set 

                // number with only the 3rd bit as set - 10000
                // so if the AND of 101 ( 5 ) and 10000 is '1' then the 3rd bit 
                // is set , if '0' then the 3rs bit is unset 

                1<<0 = 1
                1<<1 = 10 
                1<<2 = 00100
                1<<3 = 0001000

                subtracting one from all the numbers above ( binary numbers )
                00100 - 1 = 00011 ( 3 )
                1000 - 1 = 0111 ( 7 )
                10000 - 1 = 01111 ( 15 )
    */

        
void printBinary(int num)
{
    for(int i=10;i>=0;--i)
    {
        cout<<((num>>i)&1);
        // right shifting 
    }
    cout<<"\n";
}
int main()
{
    printBinary(9);
    int a = 9;
    int i = 3;
    if((a&(1<<i))!=0)
    {
        cout<<"\nset bit\n";
    }
    else
    {
        cout<<"\nnot set bit\n";
    }


    /* 
        to set the 1st bit
     then , we will take a number whose 1st bit is set to 1 
     and use OR 
    */
    printBinary(a | (1<<1));


    printBinary(a & (1<<1));
        /* 
        to unset the bit, perform AND operation with the binary number 

        example - number  = 0001001
            the number that we want  to make the 3rd bit unset = 1110111
                how do we get the numebr? 

                the number is the inverse of 0001000 , so we will invert the
                number
        
        to invert , use ( ~ ) ( tilda opeartor )s
    */

    printBinary(~a);

    printBinary(a & (~(1<<i)));


    // toggle the bit 
    // the ith position, will be 0 and the rest positions will be 1 
    // use XOR oparation
    printBinary(a ^ (1<<i));
    // XOR operator , inverts / on-offs the bits 


    // bit count
    // counting the bits 
    int ct=0;
    for(int i=31;i>=0;i--)
    {
        if((a&(1<<i))!=0)
        {
            ct++;
        }
    }
    cout<<ct<<"\n";

    return 0;
}