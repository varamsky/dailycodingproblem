#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head;

void display(){
	Node* temp = head;

	cout << "list is : ";
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << '\n';
}

void insertAt(int element,int index){
	Node* newNode = new Node();

	newNode->data = element;
	newNode->next = NULL;
	if(index == 0){
		newNode->next = head;
		head = newNode;
		display();
		return;	
	}

	Node* temp = head;
	for(int i=0;i<index-1;i++){
		cout << "at : " << temp->data << "\n";
		temp = temp->next;	
	}
	cout << "temp->next = " << temp->next << " end\n";


	newNode->next = temp->next;
	temp->next = newNode;

	display();

}

void insertLast(int element){
	Node* newNode = new Node();
	newNode->data = element;
	newNode->next = NULL;

	Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = newNode;	

	display();
}

void deleteLast(){
	Node* temp = head;

	while((temp->next)->next != NULL){
		temp = temp->next;
	}

	Node* lastNode = temp->next;

	temp->next = NULL;

	free(lastNode);

	display();
}

void deleteAt(int index){
	Node* temp = head;

	if(index == 0){
		Node* deleteNode = temp;

		head = deleteNode->next;

		free(deleteNode);
	
		cout << "\nDeleted node at index : " << index << '\n';

		display();

		return;
	}

	for(int i=0;i<index-1;i++){
		temp = temp->next;
	}

	Node* deleteNode = temp->next;

	temp->next = deleteNode->next;

	free(deleteNode);

	cout << "\nDeleted node at index : " << index << '\n';

	display();
}

void updateAt(int element,int index){
	Node* temp = head;

	for(int i=0;i<index;i++){
		temp = temp->next;
	}

	temp->data = element;

	
	cout << "\nUpdated node at index : " << index << " with new value =  " << element << '\n';

	display();
}


int main(){
	head = NULL;

	insertAt(3,0);
	insertAt(1,1);
	insertAt(4,2);
	insertAt(1,3);
	insertAt(0,0);
	insertAt(99,1);
	insertAt(6,4);
	insertAt(9,5);
	insertAt(5,6);

	insertLast(10);
	insertLast(11);
	insertLast(12);
	insertLast(13);
	insertLast(14);

	updateAt(-1,5);
	updateAt(55,10);
	updateAt(20,9);
	updateAt(1,0);

	deleteLast();
	deleteLast();
	deleteLast();
	deleteLast();
	deleteLast();
	deleteLast();
	deleteLast();

	deleteAt(1);
	deleteAt(3);
	deleteAt(0);

	return 0;
}


