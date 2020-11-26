/*

[Medium]

This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.

*/

#include <iostream>
#include <map>
#include <unordered_set>
#include <string>

using namespace std;

// My recursive solution, it works but the Time Complexity is exponential
/*int check(string s,int index,int size,int result){
    if(index >= size)
        return result;

    for(int i=index;i<size;i++){
        if(s[i] == '1' || s[i] == '2'){
            if((i+1) < size){
                if((i+2) < size){
                    if(s[i+2] == '0'){
                        continue;
                    }
                }
                if(s[i] == '1' && s[i+1] != '0'){
                    result++;
                    result = check(s,i+2,size,result);
                }
                else if(s[i] == '2'){
                    if((s[i+1] != '0' && s[i+1] <= 54)){
                        result++;
                        result = check(s,i+2,size,result);
                    }
                }
            }
        }
    }

    return result;
}

int decoding(string s){
    if(s == "0" || s[0] == '0')
        return 0;

    int size = s.size();

    for(int i=0;i<size;i++){
        if(i+1 < size)
            if(s[i] == '0' && s[i+1] == '0')
                return 0;
    }

    return check(s,0,size,1);
}*/


// The above recursive solution can easily be shortened(it's uselessly complex and can be done with fewer if-statements)
// and also the time complexity can be reduced by saving the results of previous steps by dynamic programming
// Dynamic programming approach
int decoding(string s){
    int size = s.size();

    if(size == 0 || s[0] == '0')
        return 0;
    if(size == 1)
        return 1;

    int dp[size+1]; // each time we will make a call to dp[n-1] and dp[n-2], therefore, here we take size + 1 sized array

    dp[0] = 1; // if there is no characters in the string then there is only 1 way to decode it, i.e., decoded string will also be an empty string
    dp[1] = 1; // if there is only 1 characters then there is obviously only 1 way to decode it.

    for(int i=2;i<=size;i++){ // as we have an extra-sized array, we run it till i == size
        dp[i] = 0;

        // at every step we use the results of previous steps stored in the dp[] array
        // for example,
        // if we have "10123" and we have calculated the result till the 2 at index 3
        // i.e., result for [1012] is calculated now we want to check for 3
        // 3 can either be decoded independently as 'C' (this is done in the immediate if-statement below)
        // or it can be decoded in conjunction with 2 as 23 or 'W' (this is done in the later if-statement below)
        if(s[i-1] > '0') // '0' can't be counted independently
            dp[i] = dp[i-1]; // here we count all the decoding possibities till i-1
        
        if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7'))
            dp[i] += dp[i-2]; // here, as s[i-1] & s[i-2] are decoded in conjunction therefore, we will only counts the decoding possibilities till dp[i-2]
    }

    return dp[size];
}

int main(){
    //string message = "111";
    //string message = "12";
    //string message = "226";
    //string message = "0";
    //string message = "457";
    //string message = "10";
    //string message = "100"; // ans = 0
    //string message = "2101"; // ans = 1
    string message = "1123"; // ans = 5


    cout << "Number of ways = " << decoding(message) << endl;
}