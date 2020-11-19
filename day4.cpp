/*

[Hard]

This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.

*/

#include <iostream>

using namespace std;

int segregate(int *arr,int size){
    int j = 0, i;
    for (i = 0; i < size; i++) {
        if (arr[i] <= 0) {
            arr[i] += arr[j];
            arr[j] = arr[i] - arr[j];
            arr[i] = arr[i] - arr[j];
            j++;
        }
    }
    return j;
}

int findMissing(int arr[], int size){
    int i;
  
    // Mark arr[i] as visited by making arr[arr[i] - 1] negative.
    // Note that 1 is subtracted because index start
    // from 0 and positive numbers start from 1
    for (i = 0; i < size; i++) { 
        if (abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }
  
    // Return the first index value at which is positive
    for (i = 0; i < size; i++)
        if (arr[i] > 0)
            // 1 is added because indexes start from 0
            return i + 1;
  
    return size + 1;
}

int firstMissingPositive(int arr[], int size){
    // First separate positive and negative numbers
    int shift = segregate(arr, size);
  
    // Shift the array and call findMissingPositive for
    // positive part
    return findMissing(arr + shift, size - shift);
}

int main(){
    //int arr[] = {3,4,-1,1};
    //int arr[] = {1,2,0};
    //int arr[] = {7,8,9,11,12};
    //int arr[] = {-1,-2,-60,40,43};
    //int arr[] = {};
    //int arr[] = {0};
    //int arr[] = {2};
    //int arr[] = {1};
    int arr[] = {-1,-2};

    int size = sizeof(arr)/sizeof(arr[0]);

    cout << firstMissingPositive(arr,size) << endl;

    return 0;
}