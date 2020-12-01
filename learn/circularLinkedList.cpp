/*

Implement a Circular Singly Linked List

*/

#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

class CircularLinkedList{
    private:
        Node *head;
    
    public:
        CircularLinkedList(){
            head = NULL;
        }

        // This function inserts at the end
        void insert(int element){
            Node *newNode = new Node();
            newNode->data = element;
            newNode->next = head;

            if(head == NULL){
                head = newNode;
                head->next = head;
                return;
            }

            Node *temp = head;

            while(temp->next != head){
                temp = temp->next;
            }

            temp->next = newNode;
        }

        // This function inserts at particular index
        void insertAt(int element,int index){
            if(index < 0 || index > length()){
                cout << "Invalid index" << endl;
                return;
            }

            Node *newNode = new Node();
            newNode->data = element;
            newNode->next = NULL;

            if(index == 0){
                newNode->next = head;

                Node *temp = head;
                while(temp->next != head){
                    temp = temp->next;
                }

                temp->next = newNode;
                head = newNode;
            }
            else if(index == length()){
                Node *temp = head;
                while(temp->next != head){
                    temp = temp->next;
                }

                temp->next = newNode;
                newNode->next = head;
            }
            else{
                Node *temp = head;
                int i=0;

                while(i < index-1){
                    temp = temp->next;
                    i++;
                }

                newNode->next = temp->next;
                temp->next = newNode;
            }
        }

        // This function deletes at particular index
        void deleteAt(int index){
            if(index < 0 || index > length()){
                cout << "Invalid index" << endl;
                return;
            }

            if(index == 0){
                Node *temp = head;
                while(temp->next != head){
                    temp = temp->next;
                }
                temp->next = head->next;

                temp = head;
                head = head->next;

                free(temp);
            }
            else if(index == length()-1){
                Node *temp = head;
                while(temp->next->next != head){
                    temp = temp->next;
                }

                Node *del = temp->next;
                temp->next = head;

                free(del);
            }
            else{
                Node *temp = head;
                int i=0;
                while(i < index-1){
                    temp = temp->next;
                    i++;
                }

                Node *del = temp->next;
                temp->next = del->next;

                free(del);
            }
        }

        int length(){
            Node *temp = head;

            int l=0;
            while(temp->next != head){
                l++;
                temp = temp->next;
            }
            l++;

            return l;
        }

        void display(){
            Node *temp = head;

            cout << temp->data << " -> ";
            temp = temp->next;

            while(temp != head){
                cout << temp->data << " -> ";

                temp = temp->next;
            }
            cout << temp->data << " this last one is the head therefore, circular" << endl;
        }
};

int main(){
    CircularLinkedList cll;
    
    cll.insert(1);
    cll.insert(2);
    cll.insert(3);
    cll.insert(5);
    cll.insert(7);

    cll.display();

    cll.insertAt(9,0); // at start
    cll.display();
    
    cll.insertAt(12,cll.length()); // at end
    cll.display();
    
    cll.insertAt(10,2); // in between
    cll.display();

    cll.deleteAt(0); // at start
    cll.display();
    
    cll.deleteAt(cll.length()-1); // at end
    cll.display();
    
    cll.deleteAt(2); // in between
    cll.display();

    return 0;
}
