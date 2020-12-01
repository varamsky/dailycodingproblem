// find sqrt with fractional part
#include <iostream>

using namespace std;

float mySqrt(int num,int p){
    long begin = 0, end = num;
    float ans=0;

    // integer part
    while(begin <= end){
        long mid = begin + ((end - begin) / 2);
        long sq = mid * mid;

        if(sq == num){
            ans += mid;
            break;
        }
        else if(sq > num)
            end = mid - 1;
        else
            begin = mid + 1;
    }

    if(ans == 0)
        ans = begin - 1;
    


    float inc = 0.1;

    // decimal part
    for(int i=0;i<p;i++){
        while((ans * ans) <= num){
            ans += inc;
        }

        ans -= inc;
        inc /= 10;
    }



    return ans;
}

int main(){
    int num,p;

    cout << "Enter a number : ";
    cin >> num;

    cout << "Upto how many decimal places : ";
    cin >> p;

    cout << "Square root of " << num << " upto " << p << " decimal places " << " is " << mySqrt(num,p) << '\n';
}

