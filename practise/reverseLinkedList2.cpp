#include <iostream>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

struct Node* head;

void display(){
	Node* temp = head;

	cout << "List is => ";
	while(temp != NULL){
		cout << temp->data << " ";

		temp = temp->next;
	}

	cout << "\n";
}

void reverseList(){
	//Node *prevNode,*currentNode,*nextNode; // this works well
	//Node* prevNode,currentNode,nextNode; // this gives error
	//Node* prevNode,*currentNode,*nextNode; // Now, this works fine

	Node *prevNode,*currentNode,*nextNode; // Better to just use this



	nextNode;

	currentNode = head;
	prevNode = NULL;

	while(currentNode != NULL){
		nextNode = currentNode->next;
		
		currentNode->next = prevNode;

		prevNode = currentNode;
		
		currentNode = nextNode;
	}

	head = prevNode;

	display();
}

void recursiveReverseList(Node *temp){
	if(temp->next == NULL){
		head = temp;
		return;
	}

	recursiveReverseList(temp->next);

	Node *nextNode = temp->next;
	nextNode->next = temp;
	temp->next = NULL;
}

void insert(int element){
	Node* newNode = new Node();
	newNode->data = element;
	newNode->next = NULL;

	if(head == NULL){
		head = newNode;

		head->next = NULL;
		display();
		return;
	}

	Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = newNode;

	display();
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

	//reverseList();
	recursiveReverseList(head);
	display();

	return 0;
}


