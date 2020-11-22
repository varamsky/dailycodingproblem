/*

[Medium]

This problem was asked by Twitter.

Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.

*/

#include <iostream>
#include <string>

using namespace std;

// TODO try implementation using Trie data structure

// this method uses array but other solutions online use TRIE as the data structure of choice
// time complexity of this solution is O(n) why shouldn't I just use this??
void autocomplete(string dic[],int size,string query){
    string arr[size];
    for(int i=0;i<size;i++)
        arr[i] = dic[i].substr(0,query.size());
    
    for(int i=0;i<size;i++){
        if(arr[i] == query)
            cout << dic[i] << " ";
    }
    cout << endl;
}

int main(){
    string dictionary[] = {"dog", "deer", "deal","drug","de"};
    string query = "de";
    int size = sizeof(dictionary) / sizeof(dictionary[0]);

    autocomplete(dictionary,size,query);

    return 0;
}
