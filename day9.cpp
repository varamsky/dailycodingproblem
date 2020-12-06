/*

[Hard]

This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?

*/

#include <iostream>

using namespace std;

int non_adjacent_sum(int arr[],int size){
    if(size < 1)
        return 0;
    
    int first,second = 0;

    for(int i=0;i<size;i++){
        int curr_sum = max((arr[i]+second),first);

        second = first;
        first = curr_sum;
    }

    return first;
}

int main(){
    int arr[] = {2,4,6,2,5};
    //int arr[] = {5,1,1,5};
    //int arr[] = {5,-1,3,-2,1};
    //int arr[] = {5,9,3,-2,8,-4,-6,6};
    //int arr[] = {5};
    //int arr[] = {};
    cout << "Non-adjacent sum = " << non_adjacent_sum(arr,sizeof(arr)/sizeof(arr[0])) << endl;

    return 0;
}
