#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearchRecursive(vector<int> arr,int search,int begin,int end){
    int mid = begin + ((end-begin) / 2);

    if(begin <= end){
        if(arr[mid] == search)
            return mid;
        else if(arr[mid] > search)
            return binarySearchRecursive(arr,search,begin,end-1);
        else
            return binarySearchRecursive(arr,search,begin+1,end);
    }

    return -1;
}

int main(){
    int size;
    vector<int> arr;
    int search;

    cout << "Enter size : ";
    cin >> size;

    cout << "\nEnter numbers : ";
    for(int i=0;i<size;i++){
        int temp;
        cin >> temp;

        arr.push_back(temp);
    }

    cout << "\nEnter number to be searched : ";
    cin >> search;

    sort(arr.begin(),arr.end());

    cout << "\nFound at index :  " << binarySearchRecursive(arr,search,0,arr.size()-1) << '\n';
}
