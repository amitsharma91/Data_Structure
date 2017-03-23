#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* link;
	Node(){}

};

class LinkedList{
	public:
	Node* start;
	LinkedList(){start = NULL;cout << "This is Object Creation";}
	void insertAtBeg(int);
	void insertLast(int);
	void display();
	void initList(int);
	Node* createNode(int);

};

void LinkedList::insertAtBeg(int data){
	cout << "INto Insertion" << endl;

	if(start == NULL) {
		initList(data);

	} else {
		Node* tempNode = createNode(data);
		tempNode->link = start;
		start = tempNode;
 	}
	//cout << "Data in start node" << start->data;
}

Node* LinkedList::createNode(int data){
	cout << "INTO Create Node"<< endl;
	Node *tempNode = new Node();
	tempNode->data = data;
	tempNode->link = NULL;
	return tempNode;
}

void LinkedList::initList(int data){
	cout << "INTO Init List"<< endl;
	start = createNode(data);
}

void LinkedList::insertLast(int data){
	cout << "INTO INSERT AT LAST"<< endl;

	if(start == NULL) {
		initList(data);
	} else {
		Node* tempNode = new Node();
		tempNode = start;
		cout << tempNode->data;
		while(tempNode->link !=NULL)
			tempNode=tempNode->link;

		tempNode->link = createNode(data);

	}
}


void LinkedList::display(){
	cout << endl<<"In Display.."<< endl;
	Node* Temp = new Node();
	Temp = start;

	while(Temp!=NULL){
		cout << Temp->data << "\t ->";
		Temp = Temp->link;
	}
	cout << endl;
}

int main(){

	cout << "Into Main" << endl;
	LinkedList l;
	cout << "Object is created...";
	cout << "Callint Insert";
	l.insertAtBeg(5);
	l.insertAtBeg(55);
	l.insertAtBeg(555);
	//cout << "Data in start node inside main" << l.start->data;
	cout << "Data in LinkedList: "<< endl;
	l.display();
	l.insertLast(789);
	l.insertLast(7899);
	l.insertAtBeg(35);
	l.insertAtBeg(25);
	l.display();

	return 0;
}
