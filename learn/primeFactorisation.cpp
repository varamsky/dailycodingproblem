// program to print prime factorisation of a number
#include <iostream>
#include <cmath>

using namespace std;

// Time complexity is O(n)
/*void primeFactorisation(int n){
    for(int i=2;i<=n;i++){ // in worst case i.e., n is prime time complexity for this loop is O(n)
        if(n%i == 0){
            int count = 0;
            while(n%i == 0){ // in worst case i.e., n is prime time complexity for this loop is O(1) that is loop will run only 1 time when i == n
                count++;

                n = n / i;
            }
            cout << i << "^" << count << " X ";
        }
    }
}*/

// BETTER => Time complexity is O(sqrt(n))
void primeFactorisation(int n){
    for(int i=2;i<=(int)sqrt(n);i++){ // in worst case i.e., n is prime time complexity for this loop is O(sqrt(n))
        if(n%i == 0){
            int count = 0;
            while(n%i == 0){ // in worst case i.e., n is prime time complexity for this loop is O(1) that is loop will run only 1 time when i == n
                count++;

                n = n / i;
            }
            cout << i << "^" << count << " X ";
        }
    }
    if(n != 1)
        cout << n << "^1";
}

int main(){
    int n;

    cin >> n;

    primeFactorisation(n);
    cout << '\n';
}