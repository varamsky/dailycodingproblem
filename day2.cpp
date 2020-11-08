/*

[Hard]

This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24].
If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?

*/


#include <iostream>

using namespace std;

// Simple Approach. Uses division.
/*void product(int arr[],int size){
    int result[size];
    int p = 1;

    for(int i=0;i<size;i++){
        p *= arr[i];
    }

    cout << "Result : ";
    for(int i=0;i<size;i++){
        result[i] = p / arr[i];

        cout << result[i] << " ";
    }
    cout << "\n";
}*/

// Without division BUT with nested loop
/*void product(int arr[],int size){
    int result[size];

    for(int i=0;i<size;i++){
        result[i] = 1;
        for(int j=0;j<size;j++){
            if(i != j)
                result[i] *= arr[j];
        }
    }

    cout << "Result : ";
    for(int i=0;i<size;i++){
        cout << result[i] << " ";
    }
    cout << "\n";
}*/

// left-right approach with O(n) time complexity, here space complexity isn't constant O(1)
// got this approach from leetcode
// https://leetcode.com/problems/product-of-array-except-self/solution/
void product(int arr[],int size){
    int left[size],right[size],result[size];

    left[0] = arr[0];
    right[size-1] = arr[size-1];

    for(int i=1;i<size;i++){
        left[i] = left[i-1] * arr[i];
        right[size-1-i] = right[size-i] * arr[size-1-i];
    }

    result[0] = right[1];
    result[size-1] = left[size-1-1];
    for(int i=1;i<size-1;i++){
        result[i] = left[i-1] * right[i+1];
    }

    cout << "Result : ";
    for(int i=0;i<size;i++){
        cout << result[i] << " ";
    }
    cout << "\n";
}

// O(n) time complexity and O(1) space complexity approach PENDING



int main(){
    //int arr[] = {1, 2, 3, 4, 5};
    int arr[] = {3, 2, 1};
    //int arr[] = {1,3,0,5};
    
    int size = sizeof(arr)/sizeof(arr[0]);

    product(arr,size);

    return 0;
}

