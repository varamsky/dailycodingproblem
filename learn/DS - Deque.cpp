/*

Implement Deque

*/

#include <iostream>

using namespace std;

class Deque{
    private:
        int max_size;
        int *arr;
        int front;
        int rear;
    
    public:
        Deque(int size){
            max_size = size;
            arr = new int[max_size];
            front = -1;
            rear = 0;
        }

        bool isEmpty(){
            return front == -1;
        }

        bool isFull(){
            return rear == max_size-1;
        }

        void traversal(){
            if(isEmpty() == true){
                cout << "Empty Queue!!" << endl;
                return;
            }

            cout << "Deque : ";
            while(front != rear){
                cout << arr[front] << "  ";

                front = ++front % max_size;
            }
            cout << arr[front++] << endl;
        }

        void enqueueFront(int element){
            if(isFull() == true){
                cout << "Queue Overflow!!" << endl;
                return;
            }

            cout << "Enqueue Front : " << element << endl;

            front = (front == -1)?0:(front-1 < 0)?max_size-1:front - 1;
            arr[front] = element;
        }

        void enqueueRear(int element){
            if(isFull() == true){
                cout << "Queue Overflow!!" << endl;
                return;
            }

            cout << "Enqueue Rear : " << element << endl;

            front = (front == -1)?0:front;

            arr[++rear % max_size] = element;
        }

        void dequeueFront(){
            if(isEmpty() == true){
                cout << "Deque Underflow!!" << endl;
                return;
            }

            cout << "Deque Front" << endl;

            front = (front+1) % max_size;
        }

        void dequeueRear(){
            if(isEmpty() == true){
                cout << "Deque Underflow!!" << endl;
                return;
            }

            cout << "Deque Rear" << endl;

            rear = (rear-1) % max_size;
        }

};

int main(){
    Deque dq(5);

    dq.traversal();

    dq.enqueueFront(2);
    dq.enqueueFront(4);

    dq.traversal();

    dq.enqueueFront(2);
    dq.enqueueFront(4);
    dq.enqueueRear(7);
    dq.enqueueRear(1);

    dq.traversal();

    dq.enqueueFront(2);
    dq.enqueueFront(4);
    dq.enqueueRear(7);
    dq.enqueueRear(1);
    dq.dequeueFront();
    dq.dequeueRear();

    dq.traversal();

    return 0;
}
