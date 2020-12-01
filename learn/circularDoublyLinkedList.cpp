/*

Implement a Circular Doubly Linked List

*/

#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

class CircularDoublyLinkedList{
    private:
        Node *head;
        Node *tail;
    public:
        CircularDoublyLinkedList(){
            head = NULL;
            tail = NULL;
        }

        // This function inserts at the end
        void insert(int element){
            Node *newNode = new Node();
            newNode->data = element;
            newNode->prev = NULL;
            newNode->next = NULL;

            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            else if(head->next == NULL){
                head->next = newNode;
                newNode->next = head;
                head->prev = newNode;
                newNode->prev = head;
                tail = newNode;
                return;
            }

            Node *temp = head;
            while(temp->next != head){
                temp = temp->next;
            }

            newNode->prev = temp;
            temp->next = newNode;
            tail = newNode;
            head->prev = tail;
            tail->next = head;
        }

        // This function inserts at a particular index
        void insertAt(int element,int index){
            if(index < 0 || index > length()){
                cout << "Invalid index" << endl;
                return;
            }

            Node *newNode = new Node();
            newNode->data = element;
            newNode->prev = NULL;
            newNode->next = NULL;

            if(index == 0){
                newNode->next = head;
                head->prev = newNode;

                head = newNode;

                head->prev = tail;
                tail->next = head;

                return;
            }
            else if(index == length()){
                tail->next = newNode;
                newNode->prev = tail;

                tail = newNode;

                tail->next = head;
                head->prev = tail;

                return;
            }

            Node *temp = head;
            int i=0;
            // 1 -> 2 -> 3 -> 4
            while(i < index - 1){
                temp = temp->next;
                i++;
            }

            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
        }

        void deleteAt(int index){
            if(index < 0 || index >= length()){
                cout << "Invalid index" << endl;
                return;
            }

            if(index == 0){
                Node *temp = head;
                head = head->next;
                head->prev = tail;
                tail->next = head;

                free(temp);
                return;
            }
            else if(index == length()-1){
                Node *del = tail;
                tail = tail->prev;
                tail->next = head;
                head->prev = tail;

                return;
            }

            int i=0;
            Node *temp = head;
            while(i < index-1){
                temp = temp->next;
                i++;
            }

            Node *del = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;

            free(del);
        }

        int length(){
            Node *temp = head;

            int l=0;
            while(temp->next != head){
                temp = temp->next;
                l++;
            }
            l++;

            return l;
        }

        void display(){
            Node *temp = head;

            cout << "Forward Doubly Linked List => ";
            while(temp->next != head){
                cout << temp->data << " -> ";

                temp = temp->next;
            }
            cout << temp->data << "\nReverse Doubly Linked List => ";

            temp = tail;
            while(temp->prev != tail){
                cout << temp->data << " -> ";

                temp = temp->prev;
            }
            cout << temp->data << "\nhead->prev->data = " << head->prev->data << " and tail->next->data = " << tail->next->data << "\n\n";
        }
};

int main(){
    CircularDoublyLinkedList cdll;

    cdll.insert(5);
    cdll.insert(3);
    cdll.insert(7);
    cdll.insert(1);
    cdll.insert(8);

    cdll.display();

    cdll.insertAt(9,0); // insert at start
    cdll.display();

    cdll.insertAt(10,cdll.length()); // insert at end
    cdll.display();
    
    cdll.insertAt(6,2);
    cdll.display();

    cdll.insertAt(10,3);
    cdll.display();

    cdll.deleteAt(0); // delete at start
    cdll.display();

    cdll.deleteAt(cdll.length()-1); // delete at end
    cdll.display();

    cdll.deleteAt(3); // delete in between
    cdll.display();

    return 0;
}