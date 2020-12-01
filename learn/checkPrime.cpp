// Program to check a number is prime or not
#include <iostream>
#include <cmath>

using namespace std;

string checkPrime(int n){
    cout << "factors of " << n << " except 1 and itself : ";
    int f = 0;

    // NAIVE METHOD => Time Complexity is O(n)
    /*for(int i=2;i<n;i++){
        if(n % i == 0){
            cout << i << ", ";
            f++;
        }
    }*/

    // BETTER METHOD => Time Complexity is O(n/2)
    /*for(int i=2;i<=(n/2);i++){
        if(n % i == 0){
            cout << i << ", ";
            f++;
        }
    }*/

    //cout << "Square root : " << (int)sqrt(n);
    int s = (int)sqrt(n);
    //cout << "Square root : " << s << '\n';

    // BEST METHOD BEST TIME COMPLEXITY  => Time Complexity is O(sqrt(n))
    for(int i=2;i<=(int)sqrt(n);i++){
        if(n % i == 0){
            int co = n / i;
            cout << i << ", ";
            cout << co << ", ";

            if(i == co)
                f++;
            else
                f+=2;
        }
    }

    cout << "f = " << f << '\n';

    if(f == 0)
        return "Yes";
    else
        return "No";
    
}


int main(){
    int n;

    cin >> n;

    cout << checkPrime(n) << '\n';
}