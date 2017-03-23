#include<iostream>
using namespace std;

class Node{
	public:	
	int data;
	Node* next;
};

class Stack{
	public:
	Node* top;
	Stack():top(NULL){}

	Node* createNode(int);
	void push(int);
	void pop();
	int getTop();
	void display();	
	int count();
};

Node* Stack::createNode(int data){
	Node* tempNode = new Node();
	tempNode->data = data;
	tempNode->next = NULL;
	return tempNode;
}

void Stack::push(int data){
	Node* tempNode = createNode(data);
	if(top == NULL){
		top = tempNode;
		return;
	}
	tempNode->next = top;
	top = tempNode;
}

void Stack::pop(){
	if(top == NULL){
		cout << "No Elements to remove. Stack is Empty" << endl;
		return;
	}
	Node* tempNode = top;
	top = tempNode->next;
	tempNode = NULL;	
}

void Stack::display(){
	if(top == NULL){
		cout << "ERROR: No Elements to Remove. Stack is Empty." << endl;
		return;
	}
	Node* tempNode = top;
	cout << "Stack Element are: ";
	while(tempNode != NULL)
	{
		cout << tempNode->data << " --> ";
		tempNode = tempNode->next;
	}
	cout << endl;
}
	
int Stack::getTop(){
	if(top == NULL){
		cout << "ERROR: Stack is Empty" << endl;
	}
	Node* tempNode = top;
	return tempNode->data;
}

int Stack::count(){
	if(top == NULL)	
		return 0;
	else{
		Node* tempNode = top;
		int cnt = 1;
		while(tempNode->next != NULL){
			tempNode = tempNode->next;++cnt;
		}
		return cnt;
	}
}

int main(){

	Stack s;
	while(true){
		cout << "\n1: PUSH\n2: POP\n3: TOP\n4: display\n5: Size" << endl;
		cout << "Select an Operation: ";int op;cin >> op;
		switch(op){
			case 1:{
							cout << "Enter an Element to Push to Satack: ";
							int el;cin >> el;
							s.push(el);
					}break;
			case 2:{
							s.pop();
					}break;
			case 3:{
							cout << "Elements at Top is: " << s.getTop() << endl;
					}break;
			case 4:{
							s.display();
					}break;
			case 5:{
							cout << "No. of Elements in Stack are: " << s.count() << endl;
					}break;
		}		
	}
	return 0;
}
