/*

[Hard]

This problem was asked by Amazon.

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

*/


#include <iostream>
#include <unordered_set>

using namespace std;

int longsubstring(int* start,int* end,string s,int k){
	unordered_set<char> chars;
	//cout << "start = " << *start << " end = " << *end << endl;

	int size = *end - *start + 1;
	for(int i=*start;i<=*end;i++)
		chars.insert(s[i]);

	if(chars.size() > k){
		(*start)++;
		return -1;
	}
	else{
		if(((*end) + 1) >= s.size())
			(*start)++;
		else
			(*end)++;
	}

	//cout << "size = " << size << endl;

	return size;
}

int main(){
	string s;
	cin >> s;

	int k;
	cin >> k;

	// s="aabbcc", k = 1 => result=2
	// s="aabbcc", k = 2 => result=4
	// s="aabbcc", k = 3 => result=6
	// s="aabacbebebe", k = 3 => result=7

	int start=0,end=0,l=-1;

	while(start < s.size()){
		int subl = longsubstring(&start,&end,s,k);
		l = (subl > l)?subl:l;
	}

	cout << "max length = " << l << endl;

	return 0;
}

