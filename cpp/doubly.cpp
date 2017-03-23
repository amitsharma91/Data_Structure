#include<iostream>
using namespace std;

class Node{
	public:	
	int data;
	Node* prev;
	Node* next;
};

class Doubly{
	public:
	Node* head;
	Doubly():head(NULL){}
	
	Node* createNode(int);
		
	void insertAtBeg(int);
	void insertAtLst(int);
	void insertBeforeN(int,int);
	void insertAfterN(int,int);
	void insertAtN(int,int);
	
	void deleteBeg();
	void deleteLst();
	void deleteElement(int);
	
	void search(int);
	void showForw();
	void showBack(Node*);
	void reverseNorm();
	void reverseRec();
	int count();
};

Node* Doubly::createNode(int data){
	Node* tempNode = new Node();
	tempNode->data = data;
	tempNode->prev = NULL;
	tempNode->next = NULL;
	return tempNode;
}

void Doubly::insertAtBeg(int data){
	if(head == NULL){
		Node* tempNode = createNode(data);
		head = tempNode;
		return;		
	}
		Node* tempNode = createNode(data);
		tempNode->next = head;
		head = tempNode;	
}

void Doubly::insertAtLst(int data){
	if(head == NULL){
		Node* tempNode = createNode(data);
		head = tempNode;
		return;
	}	
	Node* tempNode = head;
	while(tempNode->next != NULL)
		tempNode = tempNode->next;
	
	//cout << "Last Node Data is: " << tempNode->data << endl;
	Node* newNode = createNode(data);
	tempNode->next = newNode;
	newNode->prev = tempNode;			
}

void Doubly::insertBeforeN(int ele,int data){
	if(head->next->data == ele){
		cout << "To be inserterted at begining" << endl;
		return;		
	}
	Node* tempNode = head;
	
	while(tempNode->next != NULL){
		if(tempNode->next->data == ele){
			Node* newNode = createNode(data);
			newNode->next = tempNode->next;
			newNode->prev = tempNode;
			
			tempNode->next->prev = newNode;
			tempNode->next = newNode;
			return;
		}tempNode = tempNode->next;
	}
	cout << "Element does not exists in the List" << endl;
}

void Doubly::insertAfterN(int ele,int data){
	Node* tempNode = head;
	while(tempNode->next != NULL){
		if(tempNode->data == ele && tempNode->next->next == NULL){
			Node* newNode = createNode(data);
			newNode->prev = tempNode;
			
			tempNode->next = newNode;
		}
		if(tempNode->data == ele && tempNode->next->next != NULL){
			Node* newNode = createNode(data);
			newNode->next = tempNode->next;
			newNode->prev = tempNode;
			
			tempNode->next->prev = newNode;
			tempNode->next = newNode;
			return;
		}
		tempNode = tempNode->next;
	}
	cout << "Element does not exists in the List" << endl;
}

void Doubly::insertAtN(int pos,int data){
	if(pos ==1 && head != NULL){
		Node* newNode = createNode(data);
		newNode->next = head->next;
		head = newNode;
		return;
	}
	
	Node* tempNode = head;
	for(int i=1;i<pos-1 && tempNode!= NULL;i++)
		tempNode = tempNode->next;

	Node* newNode = createNode(data);
	newNode->next = tempNode->next;
	newNode->prev = tempNode;
	
	tempNode->next->prev = newNode;
	tempNode->next = newNode;
}

void Doubly::deleteBeg(){
	Node* tempNode = head;
	head = tempNode->next;
	tempNode = NULL;	
	//cout << "Element at tempNode is: " << tempNode->data << endl;
}

void Doubly::deleteLst(){
	Node* tempNode = head;
	
	while(tempNode->next->next != NULL)
		tempNode = tempNode->next;
		
	tempNode->next = NULL; 
	//cout << "data is: " << tempNode->data << endl; 
}

void Doubly::deleteElement(int data){
	Node* tempNode = head;
	
	while(tempNode->next != NULL){
		if(tempNode->data == data){
			tempNode->prev->next = tempNode->next;
			tempNode->next->prev = tempNode->prev;
			tempNode = NULL;
			return;
		}
		tempNode = tempNode->next;
	}
	cout << "Element does not exists in the List" << endl;
}

void Doubly::search(int data){	
	Node* tempNode = head;
	int pos = 1;
	while(tempNode->next != NULL ){
		if(tempNode->data == data){
			cout << "Element found in List @ position-" << pos << endl;
			return;
		}
		tempNode = tempNode->next;++pos;
	}
	cout << "Element does not exists in the List" << endl; 
}

void Doubly::showForw(){
	Node* tempNode = head;
	while(tempNode != NULL){
		cout << tempNode->data << " --> ";
		tempNode = tempNode->next;
	}	
	cout << endl;
}

void Doubly::showBack(Node* p){
	if(p == NULL){
		return;
	}
	showBack(p->next);
	cout << p->data << " ";
}

void Doubly::reverseNorm(){
	Node* tempNode = head;
	while(tempNode->next != NULL){
		tempNode = tempNode->next;}

	while(tempNode != NULL){
		cout << tempNode->data << " --> ";
		tempNode = tempNode->prev;
	}
	cout << endl;
}

int Doubly::count(){
	Node* tempNode = head;
	int x = 1;
	while(tempNode->next != NULL){
		++x;
		tempNode = tempNode->next;
	}
	return x;
}

int main(){
	Doubly d;
	d.insertAtBeg(65);//d.showForw();
	d.insertAtBeg(45);//d.showForw();
	d.insertAtBeg(78);//d.showForw();
	d.insertAtBeg(32);
		
	d.insertAtLst(564);
	d.insertBeforeN(45,44);
	d.insertAfterN(45,46);
	
	d.insertAtN(4,99);
	d.showForw();

	//d.deleteElement(99);
	//d.deleteLst();
	//d.deleteBeg();
	d.showForw();
	//d.search(658);
	d.reverseNorm();

	//d.showBack(d.head);

	cout << endl << "size is: " << d.count();
	
	return 0;
}
