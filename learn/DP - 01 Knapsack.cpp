/*

Implement 01 Knapsack using DP

*/

#include <iostream>

using namespace std;

int knapsack(int W,int weights[],int values[],int size){
	int dp[size+1][W+1];

	for(int i=0;i<=size;i++){
		for(int w=0;w<=W;w++){
			if(i == 0 || w == 0)
				dp[i][w] = 0;
			else if(weights[i-1] <= w){
				int consider_item = dp[i-1][w-weights[i-1]]+values[i-1];
				int dont_consider_item = dp[i-1][w];
				dp[i][w] = max(consider_item,dont_consider_item);
			}
			else
				dp[i][w] = dp[i-1][w];
		}
	}

	return dp[size][W];
}

int main(){
	/*int weights[] = {1,2,3};
	int values[] = {10,15,40};
	int W = 6; // ans = 65
	int size = sizeof(weights)/sizeof(weights[0]);*/

	int weights[] = {10,20,30};
	int values[] = {60,100,120};
	int W = 50; // ans = 220
	int size = sizeof(weights)/sizeof(weights[0]);

	cout << "Result = " << knapsack(W,weights,values,size) << endl;
	
	return 0;
}
