// program to find an element in a circularly sorted array which is rotated
// condition1: the array must not contain duplicate elements
// condition2: we assume that the array is sorted in the anticlockwise direction i.e., towards the right
#include <iostream>

using namespace std;

// using binary search => time complexity is O(log(n))
int circularArraySearch(int arr[],int size,int search){
	int left=0,right=size-1;

	while(left <= right){
		int mid = left + ((right - left) / 2);

		if(arr[mid] == search)
			return mid;
		if(arr[mid] <= arr[right]){
			if(search >= arr[mid] && search <= arr[right])
				left = mid + 1;
			else
				right = mid - 1;
		}
		else{
			if(search >= arr[left] && search <= arr[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	return -1;
}

int main(){
	int size;

	cout << "Enter the size of array: ";
	cin >> size;

	int arr[size];

	cout << "Enter the elements of the array: ";
	for(int i=0;i<size;i++)
		cin >> arr[i];
	
	int search;

	cout << "Enter an element to be searched: ";
	cin >> search;

	cout << "Search element found at index = " << circularArraySearch(arr,size,search) << '\n';

}
