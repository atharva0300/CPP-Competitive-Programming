#include<bits/stdc++.h>
using namespace std;


/* Naive Approach */ 
int modInverse(int A,int M)
{
    A=A%M;
    for(int B=1;B<M;B++)
        if((A*B)%M)==1)
            return B;
    
    // TIme complexity ; O(M)
}

/*
    (A/B) %m  = (A*^B-1)%m
            =  ((A%m) * (B^-1)%m)%m
        
        B^-1 % m = Modular multiplicative inverse of B 

        (A * B) %m = 1
        B is modular multiplicative inverse of A ( MMI of A )
        1 <= B < M-1
        ( A %m * B%) %m =1

        M or m = modulo

        Loop B = 1 -> M -1
        (A *B )% m = 1
        time complexity = O(M)

        MMI of A with M 
        O(M)

        MMI is defied if A ad M are coprime 
        or GCD ( a,M ) =1 


        Fermett theorem - 
        A^(M-1) = 1 mod(M)

        meaning that - when A^(M-1)is divided by M , the the remider will come as 1 
        Conditions : M is prime and M is not a multiple of A 


        Example  M = 3 
            then ,taking a = 5;
            a^2 = 25
            25 % M = 1

            if A = 2
            2 ^6  = 64
            64% 3 = 1



            A^(M-1) = 1 mod ( M )
            multiplyig both the sides with A^(-1)
            A ^ (M-2) = A^-1 mod( M )
            A^(M-2) % M = A^-1

            Calculating A^(M-2) using Binary exponentiation

            MMI - Extended euclid algorithm
*/

const int M = 1e9 +7;
int binexp(int a , int b , int m)
{
    int result = 1;
    while(b>0)
    {
        if(b&1)
        {
            result = { result * 1LL * a) %m;
        }
        a = (a* 1LL *a)%m;
        b>>=1;
    }
}


// Approach 2 
int d , x , y;
int modIverse(int A , int M )
{
    extendedEuclid(A , M);
    return (x%M + M )%M;     // x may be negative

    // Time complexity - O(log(max(A,M)))
}


// Approach 3 ( used only when M is prime )
// usig Fermat's little theorem 
int modInverse3(int A , int M )
{
    return modularExponentiatio(A , M-2 ,M);
    // Time complexity : O (logn)
}


const int N = 1e6 + 10;
int fact[N];


int main()
{
    cout<<"\nInverse : ";
    cout<<binexp(2 , M-2 , M);
    cout<<"\n";


    /* 
    Question : 
    Tere are N children adn K toffees. K < N 
    Count the number of ways to distribute toffee among N students 
    such that each student gets 1 toffee.
    N < 10^9 , K < 10^9
    */

    /* 
    Answer : nCk % M , where M = 10^9+7;
    */

   /* 
    ( n! / ((n-r)! * r!) ) % M 
    */
    
   fac[0] =1;
   for(int i=1;i<N;i++)
   {
       fac[i] = (fac[i-1] * 1LL * i) % M ;
   }

   // calculating nCk
   int q;
   cin>>q;
   while(q--)
   {
       int n , k;
        cin>>n>>k;
        int ans = fac[n];
        int den = (fac[n-r] * 1LL * fac[r]) % M;
        int ans = fac[n];
        ans = ans * binexp(den , M-2 , M );
        cout<<ans<<"\n";
   }    
    return 0;
}