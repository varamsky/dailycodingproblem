// find the first and last occurances of an element in an array using Binary Search

#include <iostream>

using namespace std;

int firstOccurance(int arr[],int size,int element){
	int l=0,r=size-1;

	int result = -1;
	while(l <= r){
		int mid = l + ((r-l)/2);

		if(arr[mid] == element){
			result = mid;
			r = mid - 1;
		}
		else if(arr[mid] > element)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return result;
}

int lastOccurance(int arr[],int size,int element){
	int l=0,r=size-1;

	int result = -1;
	while(l <= r){
		int mid = l + ((r-l)/2);

		if(arr[mid] == element){
			result = mid;
			l = mid + 1;
		}
		else if(arr[mid] > element)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return result;
}
	

int main(){
	int size;

	cout << "Enter the size of the array: ";
	cin >> size;

	int arr[size];

	cout << "Enter a sorted array: ";
	for(int i=0;i<size;i++)
		cin >> arr[i];
	
	int element;

	cout << "Enter search element: ";
	cin >> element;

	int first = firstOccurance(arr,size,element);
	if(first != -1){
		int last = lastOccurance(arr,size,element);

		cout << "First occurance of " << element << " is " << firstOccurance(arr,size,element) << '\n';
		cout << "Last occurance of " << element << " is " << lastOccurance(arr,size,element) << '\n';

		int count = last - first + 1;

		cout << "Count = " << count << '\n';
	}
	else
		cout << "Element " << element << " is not present in the array\n";
}

