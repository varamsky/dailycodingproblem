/*

[Hard]

This problem was asked by Amazon.

There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time.
Given N, write a function that returns the number of unique ways you can climb the staircase.
The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2


What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X?
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.

*/

#include <iostream>

using namespace std;

// below is the solution when we have a list of steps to choose from, i.e., the follow up part of the question
// for the simple version (with either 1 or 2 steps at a time), check below, i.e., the #if 0...#endif commented part

// recursion with memoization
int climbingStairs_recursion_with_memoization(int i,int n,int steps[],int stepsSize,int memo[]){
    if(i > n)
        return 0;
    
    if(i == n)
        return 1;
    
    if(memo[i] > 0)
        return memo[i];
    
    for(int index=0;index<stepsSize;index++){
        memo[i] += climbingStairs_recursion_with_memoization(i+steps[index],n,steps,stepsSize,memo);
    }
    
    return memo[i];
}

int main(){
    int testcases[] = {2,3,4,5,11,15,23,32,45}; // answers = {2,3,5,8,144,}
    int size = sizeof(testcases)/sizeof(testcases[0]);

    //int steps[] = {1,2};
    int steps[] = {1,3,5};
    //int steps[] = {1,2,8,3};
    int stepsSize = sizeof(steps)/sizeof(steps[0]);

    // testing function climbingStairs_recursion_with_memoization()
    for(int i=0;i<size;i++){
        int memo[testcases[i]];

        for(int j=0;j<testcases[i];j++) // initializing memo to 0
            memo[j] = 0;
        
        cout << "Result for " << testcases[i] << " = " << climbingStairs_recursion_with_memoization(0,testcases[i],steps,stepsSize,memo) << endl;
    }

    return 0;
}



// below is the solution when we don't have a list of steps to choose from, i.e., we can only climb 1 or 2 steps at a time
#if 0

// recursion with memoization
int climbingStairs_recursion_with_memoization(int i,int n,int memo[]){
    if(i > n)
        return 0;
    
    if(i == n)
        return 1;
    
    if(memo[i] > 0)
        return memo[i];
    
    return memo[i] = climbingStairs_recursion_with_memoization(i+1,n,memo) + climbingStairs_recursion_with_memoization(i+2,n,memo);
}

// recursion without memoization
int climbingStairs_recursion_without_memoization(int n){
    if(n < 0)
        return 0;
    
    if(n == 0)
        return 1;

    return (climbingStairs_recursion_without_memoization(n-1)+climbingStairs_recursion_without_memoization(n-2));
}

int main(){
    int testcases[] = {2,3,4,5,11,15,23,32,45}; // answers = {2,3,5,8,144,}
    int size = sizeof(testcases)/sizeof(testcases[0]);

    // testing function climbingStairs_recursion_without_memoization()
    for(int i=0;i<size;i++)
        cout << "Result for " << testcases[i] << " = " << climbingStairs_recursion_without_memoization(testcases[i]) << endl;

    cout << "\n\n\n";

    // testing function climbingStairs_recursion_with_memoization()
    for(int i=0;i<size;i++){
        int memo[testcases[i]];

        for(int j=0;j<testcases[i];j++) // initializing memo to 0
            memo[j] = 0;
        
        cout << "Result for " << testcases[i] << " = " << climbingStairs_recursion_with_memoization(0,testcases[i],memo) << endl;
    }

    return 0;
}

#endif
