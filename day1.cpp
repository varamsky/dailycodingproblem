/*

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

*/

#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

// This is better and uses only 1 loop
// THIS APPROACH USES A HASHSET therefore space complexity is O(N)
// as nested if isn't supported in c++ #if 0 ... #endif is used here
#if 0
void addUp(int arr[],int k,int size){
    unordered_set<int> myset;
    bool found = false;

    /*
    // this version of the works as well but it FAILS as it doesn't account for k to be twice of any of the numbers in list
    // for example, if arr = [5,3,8,11] and k = 10 then this will print "Yes" as 5+5 is 10
    // the below for loop accounts for this particular case as well.

    for(int i=0;i<size;i++){
        myset.insert(arr[i]);
    }

    for(int i=0;i<size;i++){
        if(arr[i] >= k) // if arr[i] is already >= k then nothing added to this can produce the required result
            continue;
        else if(myset.find(abs(k-arr[i])) != myset.end()){
            found = true;
            break;
        }
    }

    */

    for(int i=0;i<size;i++){
        if(arr[i] >= k) // if arr[i] is already >= k then nothing added to this can produce the required result
            continue;
        else if(myset.find(abs(k-arr[i])) != myset.end()){
            found = true;
            break;
        }

        myset.insert(arr[i]);
    }

    if(found)
        cout << "Yes\n";
    else
        cout << "No\n";
}
#endif

// This uses a single loop and doesn't use any extra space
void addUp(int arr[],int k,int size){
    int l=0,r=size-1;
    bool found = false;
    sort(arr,arr+size);
    while(l<r){
        if(arr[l] + arr[r] < k)
            l++;
        else if(arr[l] + arr[r] > k)
            r--;
        else{
            found = true;
            break;
        }
    }

    if(found)
        cout << "Yes\n";
    else
        cout << "No\n";
}


// This approach uses 2 loops
/*void addUp(int arr[],int k,int size){
    bool found = false;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]+arr[j] == k){
                found = true;
                break;
            }
        }
        if(found)
            break;
    }

    if(found)
        cout << "Yes\n";
    else
        cout << "No\n";
}*/

int main(){
    /*int arr[] = {10, 15, 3, 7};
    int k = 17;*/

    int arr[] = {9, 15, 3, 7,55};
    int k = 22;

    addUp(arr,k,sizeof(arr)/sizeof(arr[0]));

    return  0;
}

