#include <iostream>

using namespace std;

// NAIVE ITERATIVE METHOD => time complexity is O(n)
/*int myPow(int num,int p){
	int ans=1;
	for(int i=1;i<=p;i++){
		ans *= num;
	}

	return ans;
}*/


// NAIVE RECURSIVE METHOD => time complexity is O(n)
/*int myPow(int num,int p){
	if(p == 0)
		return 1;
	else
		return num * myPow(num,p-1);
}*/


// BETTER RECURSIVE METHOD => time complexity is O(log(n))
int myPow(int num,int p){
	if(p == 0)
		return 1;
	else if(p % 2 == 0){
		int y = myPow(num,(p/2));
		return y*y;
	}
	else
		return num * myPow(num,p-1);
}

int main(){
	int num;
	int p;
	
	cout << "Enter the number and the power: ";
	cin >> num >> p;

	cout << "Ans: " << myPow(num,p) << '\n';
}


