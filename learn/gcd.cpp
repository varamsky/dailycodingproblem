// program to find GCD of 2 numbers
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// NAIVE METHOD
/*int naiveGCD(int a,int b){
    vector<int> factorsA;
    vector<int> factorsB;

    for(int i=1;i<=(int)sqrt(a);i++){
        if(a % i == 0){
            factorsA.push_back(i);

            if((i*i) != a)
                factorsA.push_back(a/i);
        }
    }

    int gcd = 0;
    for(int factor:factorsA){
        if(b % factor == 0 && factor > gcd){
            gcd = factor;
        }
    }

    return gcd;
}*/

// BETTER METHOD
int euclidGCD(int a,int b){
    // let a is divisor and b is dividend
    while(a != 0){
        int remainder = b % a;
        b = a;
        a = remainder;
    }
    return b;
}


int main(){
    int a,b;

    //cin >> a >> b;

    cin >> a;
    cin >> b;

    //cout << "GCD of " << a  << " and " << b << " is " << naiveGCD(a,b) << '\n';

    cout << "GCD of " << a  << " and " << b << " is " << euclidGCD(a,b) << '\n';
}

