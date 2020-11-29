// Program to find all prime numbers upto n
#include <iostream>
#include <cmath>

using namespace std;

// NAIVE METHOD
/*void findAllPrimes(int n){
    for(int i=2;i<=n;i++){
        int f = 0;
        for(int j=2;j<i;j++){
            if(i % j == 0)
                f++;
        }
        if(f == 0)
            cout << i << " is prime\n";
        else
            cout << i << " is not prime\n";
    }
}*/

// SIEVE OF ERATOSTHENES METHOD => Time Complexity is O(nlog(logn))
void findAllPrimes(int n){
    int primes[n+1]; // if primes[i] is 1 then i is prime else not

    for(int i=0;i<=n;i++)
        primes[i] = 1;
    
    primes[0] = 0; // we know that zero is not prime
    primes[1] = 0; // we know that one is not prime


    /*for(int i=2;i<=n;i++){
        if(primes[i] == 1){
            for(int j=2;(j*i) <= n;j++){
                primes[i*j] = 0;
            }
        }
    }*/


    // this is better as we only need to run till sqrt(n)
    for(int i=2;i<=(int)sqrt(n);i++){
        if(primes[i] == 1){
            for(int j=2;(j*i) <= n;j++){
                primes[i*j] = 0;
            }
        }
    }



    // this is just for displaying result
    for(int i=0;i<=n;i++){
        if(primes[i] == 1)
            cout << i << " is prime\n";
        else
            cout << i << " is not prime\n";
        
    }
    

}

int main(){
    int n;

    cin >> n;

    findAllPrimes(n);
}