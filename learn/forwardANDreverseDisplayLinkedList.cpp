#include <iostream>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

struct Node* head;

void display(Node *temp){
	if(temp == NULL)
		return;
	
	cout << temp->data << " ";
	display(temp->next);
}

void reverseDisplay(Node *temp){
	if(temp == NULL)
		return;
	
	reverseDisplay(temp->next);
	cout << temp->data << " ";
}

void insert(int element){
	Node* newNode = new Node();
	newNode->data = element;
	newNode->next = NULL;

	if(head == NULL){
		head = newNode;

		head->next = NULL;
		
		return;
	}

	Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = newNode;

}


int main(){
	head = NULL;

	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);

	cout << "Forward List is => ";
	display(head);
	cout << "\nReverse List is => ";
	reverseDisplay(head);
	cout << "\n";

	return 0;
}


