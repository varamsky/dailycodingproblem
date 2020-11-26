/*

Reverse a Linked List

*/

#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

class LinkedList{
    private:
        Node *head;
    
    public:
        LinkedList(){
            head = NULL;
        }
        void add(int element){
            Node *newNode = new Node();
            newNode->data = element;
            newNode->next = NULL;

            if(head == NULL){
                head = newNode;
                return;
            }

            Node *temp = head;

            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = newNode;
        }

        void dispay(){
            Node *temp;
            temp = head;

            while(temp != NULL){
                cout << temp->data << " -> ";

                temp = temp->next;
            }
            cout << endl;
        }

        // 1 -> 2 -> 3 -> 4 -> NULL
        // 4 -> 3 -> 2 -> 1 -> NULL
        void reverseLinkedList(){


            // This is better & shorter solution
            Node *prevNode = NULL;
            Node *currNode = head;
            while (currNode != NULL) {
                Node *nextTemp = currNode->next;
                currNode->next = prevNode;
                prevNode = currNode;
                currNode = nextTemp;
            }
            head = prevNode;

            

            // This is my lengthy solution!!
            /* if(head == NULL || head->next == NULL)
                return;
            if(head->next->next == NULL){
                Node* temp = head;
                head = head->next;

                temp->next = NULL;
                head->next = temp;
                return;
            }
            
            Node *currNode = head;
            Node *prevNode = currNode;
            Node *nextNode = currNode->next->next;

            bool isFirst = true;

            while(nextNode != NULL){
                if(isFirst){
                    currNode = currNode->next;
                    prevNode->next = NULL;
                    isFirst = false;
                }
                else{
                    currNode = nextNode;
                    nextNode = nextNode->next;
                }
                currNode->next = prevNode;
                prevNode = currNode;
            }

            head = currNode; */
        }
};

int main(){
    LinkedList ll;

    ll.add(1);
    ll.add(2);
    ll.add(3);
    ll.add(5);
    ll.add(7);

    ll.dispay();

    ll.reverseLinkedList();
    cout << "After reversing Linked List : \n";
    ll.dispay();

    return 0;
}