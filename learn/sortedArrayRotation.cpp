// program to find out how many times is a sorted array(circularly sorted array) rotated
// condition1: the array must not contain duplicate elements
// condition2: we assume that the array is sorted in the anticlockwise direction i.e., towards the right
#include <iostream>

using namespace std;

// using binary search => time complexity is O(log(n))
int findRotation(int arr[],int size){
	int low=0,high=size-1;

	while(left <= right){
		if(arr[low] <= arr[high]){
			return low;
		}
		else{
			int mid = low + ((high - low) / 2);

			if((arr[mid] < arr[mid-1]) && (arr[mid] < arr[mid+1])){
				return mid;	
			}
			else if(arr[mid] <= arr[high]){
				high = mid - 1;
			}
			else if(arr[mid] >= arr[low]){
				low = mid + 1;
			}
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
	
	cout << "Rotations = " << findRotation(arr,size) << '\n';

}
