/*

Implement a Circular Queue

*/

#include <iostream>

using namespace std;

class CircularQueue{
    private:
        int* arr;
        int max_size;
        int front;
        int rear;
    
    public:
        CircularQueue(int size){
            this->max_size = size;
            this->arr = new int[this->max_size];
            this->front = -1;
            this->rear = -1;
        }

        bool isEmpty(){
            return this->front == this->rear;
        }

        void traversal(){
            if(this->isEmpty() == true){
                cout << "Empty Queue!!" << endl;
                return;
            }

            cout << "Circular Queue : ";
            while(this->front != this->rear)
                cout << this->arr[this->front++] << "  ";
            
            cout << this->arr[this->front] << endl;
        }

        void enqueue(int element){
            int check = (this->rear+1) % this->max_size;
            if(check == this->front){
                cout << "Queue Overflow!!" << endl;
                return;
            }

            cout << "enqueue " << element << endl;

            if(this->front == -1)
                this->front = 0;

            this->rear = check;
            this->arr[this->rear] = element;
        }

        void dequeue(){
            if(this->isEmpty() == true){
                cout << "Queue Underflow!!" << endl;
                return;
            }

            this->front = (this->front+1) % this->max_size;
        }

};

int main(){
    CircularQueue cq(5);

    cq.traversal();

    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(2);
    cq.enqueue(9);
    cq.enqueue(0);
    cq.enqueue(1);

    cq.traversal();

    cq.enqueue(11);
    cq.enqueue(155);
    cq.enqueue(43);

    cq.dequeue();
    cq.dequeue();

    cq.traversal();

    return 0;
}
