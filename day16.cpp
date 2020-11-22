/*

[Easy]

This problem was asked by Twitter.

You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
You should be as efficient with time and space as possible.

*/

#include <iostream>

using namespace std;

class Log{
    int curr_index;
    int size;
    int* arr; // this is used as a circular buffer DS
    //int arr[5];

    public:
        Log(int max_size){
            curr_index = 0;
            this->size = max_size;
            arr = new int[this->size];
        }

        void record(int order_id){
            this->arr[curr_index] = order_id;
            //this->curr_index++;
            this->curr_index = (this->curr_index + 1) % (this->size);
        }

        int get_last(int i){
            //return this->arr[this->curr_index-i-1];
            return this->arr[(this->curr_index-i-1+this->size)%this->size];
        }
};

int main(){
    int max_size = 5;
    Log log(max_size); // passing max size to Log constructor

    for(int i=0;i<max_size;i++)
        log.record(i);

    for(int i=0;i<max_size;i++)
        cout << log.get_last(i) << endl;

    return 0;
}
