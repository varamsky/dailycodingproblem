/*

Implement a Doubly Linked List

*/

#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

class DoublyLinkedList{
    private:
        Node *head;
        Node *tail;
    public:
        DoublyLinkedList(){
            head = NULL;
            tail = NULL;
        }

        void insert(int element){
            Node *newNode = new Node();
            newNode->data = element;
            newNode->left = NULL;
            newNode->right = NULL;

            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }

            Node *temp = head;
            while(temp->right != NULL){
                temp = temp->right;
            }

            newNode->left = temp;
            temp->right = newNode;
            tail = newNode;
        }

        void insertAt(int element,int index){
            if(index < 0){
                cout << "Invalid index" << endl;
                return;
            }

            Node *newNode = new Node();
            newNode->data = element;
            newNode->left = NULL;
            newNode->right = NULL;

            if(index == 0){
                newNode->right = head;
                head->left = newNode;

                head = newNode;
                return;
            }

            Node *temp = head;
            int i=0;
            // 1 -> 2 -> 3 -> 4
            while(i < index - 1){
                temp = temp->right;
                i++;
            }

            newNode->right = temp->right;
            temp->right->left = newNode;
            temp->right = newNode;
            newNode->left = temp;
        }

        void deleteAt(int index){
            if(index < 0){
                cout << "Invalid index" << endl;
                return;
            }

            if(index == 0){
                Node *temp = head;
                head = head->right;
                head->left = NULL;

                free(temp);
                return;
            }

            int i=0;
            Node *temp = head;
            while(i < index-1){
                temp = temp->right;
                i++;
            }

            Node *del = temp->right;
            temp->right = temp->right->right;
            temp->right->left = temp;

            free(del);
        }

        int length(){
            Node *temp = head;

            int l=0;
            while(temp != NULL){
                temp = temp->right;
                l++;
            }

            return l;
        }

        void display(){
            Node *temp = head;

            cout << "Forward Doubly Linked List => ";
            while(temp->right != NULL){
                cout << temp->data << " -> ";

                temp = temp->right;
            }
            cout << temp->data << "\nReverse Doubly Linked List => ";

            temp = tail;
            while(temp != NULL){
                cout << temp->data << " -> ";

                temp = temp->left;
            }
            cout << "\n" << endl;
        }
};

int main(){
    DoublyLinkedList dll;

    dll.insert(5);
    dll.insert(3);
    dll.insert(7);
    dll.insert(1);
    dll.insert(8);

    dll.display();

    dll.insertAt(9,0);
    dll.display();
    
    dll.insertAt(6,2);
    dll.display();

    dll.insertAt(10,3);
    dll.display();

    dll.deleteAt(0);
    dll.display();

    dll.deleteAt(2);
    dll.display();

    return 0;
}
