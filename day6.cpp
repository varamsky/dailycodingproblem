/*

[Hard]

This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node.

Implement an XOR linked list; 
it has an add(element) which adds the element to the end,
and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python),
you can assume you have access to get_pointer and dereference_pointer functions
that converts between nodes and memory addresses.

*/

#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *both;
};

// This is a XOR Doubly-Linked List
class XORLinkedList{
    private:
        Node *head;
    
    public:
        XORLinkedList(){
            head = NULL;
        }

        Node* XOR(Node *a,Node *b){
            // returns the XOR of Node a and Node b after recasting it as a Node pointer(Node *)
            return reinterpret_cast<Node *>(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
        }

        // this function adds newNode as head
        void add(int element){
            Node *newNode = new Node();

            newNode->data = element;
            newNode->both = NULL;

            if(head == NULL){
                head = newNode;
                return;
            }

            head->both = XOR(head->both,newNode);

            newNode->both = XOR(head,NULL);

            head = newNode;
        }

        int get(int index){
            if(index < 0){
                cout << "Invalid index!! ";
                return -1;
            }

            Node *currPtr = head;
            Node *prevPtr = NULL;
            Node *nextPtr;

            while(currPtr != NULL && index > 0){
                nextPtr = XOR(prevPtr,currPtr->both);

                prevPtr = currPtr;
                currPtr = nextPtr;
                index--;
            }

            return currPtr->data;
        }

        void display(){
            Node *currPtr = head;
            Node *prevPtr = NULL;
            Node *nextPtr;

            cout << "Linked List : ";
            while(currPtr != NULL){
                cout << currPtr->data << " -> ";

                nextPtr = XOR(prevPtr,currPtr->both);
                prevPtr = currPtr;
                currPtr = nextPtr;
            }
            cout << endl;
        }
};

int main(){
    XORLinkedList xll;

    xll.add(55);
    xll.add(15);
    xll.add(44);
    xll.add(2);
    xll.add(4);
    xll.add(5);
    xll.add(77);

    int index = 3;

    cout << "Element at index " << index << " is " << xll.get(index) << endl;

    xll.display();

    return 0;
}

