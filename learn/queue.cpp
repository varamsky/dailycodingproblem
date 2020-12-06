/*

Implement the Queue Data Structure

*/

#include <iostream>

using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int max_size;
        int* arr;
    public:
        Queue(int size){
            this->max_size = size;
            this->arr = new int[this->max_size];
            this->front = this->rear = -1;
        }

        bool isEmpty(){
            if(this->rear == -1)
                return true;
            return false;
        }

        void traversal(){
            cout << "Queue is => ";
            for(int i=this->front;i<=this->rear;i++){
                cout << this->arr[i] << "  ";
            }
            cout << endl;
        }

        void enqueue(int element){
            if(this->rear == this->max_size-1)
                cout << "Queue Overflow" << endl;
            else{
                if(this->front == -1)
                    this->front++;
                this->arr[++this->rear] = element;
            }
        }

        int dequeue(){
            if(isEmpty() == true){
                cout << "Queue Underflow" << endl;
                return -1;
            }
            else{
                return this->arr[this->front++];
            }
        }
};

int main(){
    Queue queue(5);

    cout << "Queue is empty : " << queue.isEmpty() << endl;

    queue.enqueue(5);
    queue.enqueue(1);
    queue.enqueue(3);
    queue.enqueue(7);

    queue.traversal();

    cout << "Queue dequeue : " << queue.dequeue() << endl;

    queue.traversal();

    return 0;
}