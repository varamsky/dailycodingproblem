/*

Implement the Stack Data Structure

*/

// C++ STL provides stack already defined to be used directly, check the code below
#if 0
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    stack<int> s;

    s.push(1);
    s.push(8);
    s.push(3);

    cout << s.top() << endl;

    return 0;
}
#endif

#include <iostream>

using namespace std;

class Stack{
    private:
        int top;
        int max_size;
        int* arr;
    public:
        Stack(int size){
            this->max_size = size;
            this->top = -1;
            arr = new int[this->max_size];
        }

        void traverse(){
            if(this->isEmpty() == true)
                cout << "Stack is empty" << endl;
            else{
                while(this->isEmpty() == false){
                    cout << this->pop() << endl;
                }
            }
        }

        bool isEmpty(){
            if(this->top < 0)
                return true;
            return false;
        }

        int peek(){
            if(this->isEmpty() == true){
                cout << "Stack is Empty" << endl;
                return -1;
            }
            return this->arr[this->top];
        }

        void push(int element){
            if(this->top == (this->max_size)-1)
                cout << "Stack Overflow" << endl;
            else{
                this->top++;
                this->arr[this->top] = element;
            }
        }

        int pop(){
            if(this->top == -1){
                cout << "Stack Underflow";
                return -1;
            }
            else
                return this->arr[this->top--];
        }
};

int main(){
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(40);
    stack.push(50);

    cout << "Peek Top = " << stack.peek() << endl;

    cout << "Popped = " << stack.pop() << endl;

    cout << "Peek Top = " << stack.peek() << endl;

    stack.traverse();

    return 0;
}
