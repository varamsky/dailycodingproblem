#include <iostream>

using namespace std;

// BETTER RECURSIVE METHOD => time complexity is O(log(n))
int myModPow(int num,int p,int mod){
	if(p == 0)
		return 1;
	else if(p % 2 == 0){
		int y = myModPow(num,(p/2),mod);
		return (y*y)%mod;
	}
	else
		return ((num % mod) * myModPow(num,p-1,mod))%mod;
}

int main(){
	int num;
	int p;
	int mod;
	
	cout << "Enter the number, the power and the mod: ";
	cin >> num >> p >> mod;

	cout << "Ans: " << myModPow(num,p,mod) << '\n';
}


