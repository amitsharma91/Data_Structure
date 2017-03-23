#include<iostream>
#include<cstdio>
using namespace std;

class Node{
	public:
	float data;
	Node* next;
};

class LinkedList{
	public:
	Node* head;
	LinkedList():head(NULL){}
	
	Node* createNode(int);
	void insertAtBeg(int);
	void insertAtLst(int);
	void insertAfterN(int,int);
	void insertBeforeN(int,int);
	void insertAtN(int,int);
	
	void display();
	int count();
	void search(int);

	void deleteBeg();
	void deleteLst();
	void deleteElement(int);

	void reverse();
	void printRec(Node*);
	void printRevereRec(Node*);
	void reverseRec(Node*);
};

Node* LinkedList::createNode(int data){
	Node* tempNode = new Node();
	tempNode->data = data;
	tempNode->next = NULL;
	return tempNode;
}

void LinkedList::insertAtBeg(int data){
	if(head == NULL)
	{
		head = createNode(data);
	}
	else
	{
		Node* tempNode = createNode(data);
		tempNode->next = head;
		head = tempNode;
	}
}

void LinkedList::insertAtLst(int data){
	if(head == NULL){
		head = createNode(data);
	}else
	{
		Node* tempNode = head;
		while(tempNode->next!=NULL)
			tempNode = tempNode->next;
		
		tempNode->next = createNode(data);
	}
}

void LinkedList::insertAfterN(int posData,int data){
	if(head == NULL){
		cout << "Sorry List is Empty" << endl;	
	}else{
		Node* tempNode = head;

		while(tempNode != NULL){
			if(tempNode->data == posData){
				Node* newNode = createNode(data);
				newNode->next = tempNode->next;
				tempNode->next = newNode;
				return;				
			}
		
			tempNode = tempNode->next;
		}		
		cout << "Sorry Position Node-" << posData << " does not exists in the List." << endl;
	}	
}

void LinkedList::insertBeforeN(int posData,int data){
	if(head == NULL){
		cout << "Sorry List is Empty" << endl;	
		return;
	}if(head->data == posData){
		//cout << "Data at head is: " << head->data << endl;
		Node* tempNode = createNode(data);
		tempNode->next = head;
		head = tempNode;
		return;
	}	
	else{
		Node* tempNode = head;
		while(tempNode != NULL){
			if(tempNode->next->data == posData){
				Node* newNode = createNode(data);
				newNode->next = tempNode->next;
				tempNode->next = newNode;
				return;  		
			}
			tempNode = tempNode->next;				
		}
		cout << "Sorry Position Node-" << posData << " does not exists in the List" << endl;
	}
}

void LinkedList::insertAtN(int pos,int data){
	if(pos == 1){
		Node* tempNode = createNode(data);		
		tempNode->next = head;
		head = tempNode; 
		return;
	}
	Node* tempNode = head;
	for(int i=1;i<pos-1 && tempNode!=NULL;i++)
		tempNode = tempNode->next;
	
	Node* newNode = createNode(data);
	newNode->next = tempNode->next;
	tempNode->next = newNode;
	return; 	
}

void LinkedList::display(){
	Node* trav = head;
	while(trav!=NULL){
		cout << trav->data << "\t-> ";
		trav = trav->next;
	}
	cout << endl;
}

int LinkedList::count(){
	if(head == NULL)	
		return 0;
	else{
		Node* tempNode = head;
		int cnt = 1;
		while(tempNode->next != NULL){
			tempNode = tempNode->next;++cnt;
		}
		return cnt;
	}
}

void LinkedList::search(int data){
	Node* tempNode = head;
	int pos = 1;
	while(tempNode!= NULL){
		if(tempNode->data == data){
			cout << "Data Found in List @ position: " << pos << endl;
			return;	
		}
		++pos;		
		tempNode = tempNode->next;
	}
	cout << "Data Not Found in the List" << endl;
}

void LinkedList::deleteBeg(){
	Node* tempNode = head;
	head = head->next;
	cout << "Temp Data: " << tempNode -> data  << endl;
	//free(tempNode);	
	tempNode = NULL;
	//delete(tempNode);
	//delete(head);					
}

void LinkedList::deleteLst(){
	Node* tempNode = head;
	while(tempNode->next->next!=NULL)
		tempNode = tempNode->next;
		
	//Node* lastNode = tempNode->next;
	//delete lastNode;
	tempNode->next = NULL;
	
	//cout << "Data is: " << tempNode->data << endl;		
}

void LinkedList::deleteElement(int data){
	if(head == NULL){
		cout << "Sorry List is Empty" << endl;
		return;
	}
	if(head->next->data == data){
		head->next = NULL;
		return;
	}
	Node* tempNode = head;
	while(tempNode!= NULL){
		cout << "into while loop" << tempNode->data << " <--> " << tempNode->next->data <<endl;
		if(tempNode->next->data == data){
			Node* newNode = tempNode->next;
			tempNode->next =	newNode->next;
			newNode = NULL;
			return;
		}	
		tempNode = tempNode->next;	
	}
	cout << "Element Not Found in List" << endl;
}

void LinkedList::reverse(){
	Node* currentNode = head;
	Node* prev = NULL;
	Node* next = NULL;
	
	while(currentNode != NULL){
		next = currentNode->next;
		currentNode->next = prev;
		prev = currentNode;
		currentNode = next;
	}
	head = prev;
}


void LinkedList::printRec(Node* p){
	if(p == NULL)
		return;
		
	cout << p->data << " ";
	printRec(p->next);
}

void LinkedList::printRevereRec(Node* p){
	if(p == NULL)
		return;
		
	printRevereRec(p->next);
	cout << p->data << " ";
}

void LinkedList::reverseRec(Node* cur){
	if(cur == NULL){
		head = cur;
		return;
	}	
	reverseRec(cur->next);
	Node* prev = cur->next;
	prev->next = cur;
	cur->next = NULL;
}

int main(){
	LinkedList l; 
	
	char c;
	do{
		int ch;
		cout << "01: Insert at Begining" << endl <<
				 "02: Insert at Last\n03: Insert After Element\n04: Insert Before Element" << endl <<
				"05: Insert at Nth Position\n06: Display\n07: Show Count\n08: Search Element"
				"\n09: Delete from Begining"
				<< endl << "10: Delete an Element\n11: Delete Last Element\n12: Reverse\n13: Display Reverse";
		cout << endl << "\nSelect Option: ";	cin >> ch;

		switch(ch){
			case 1:{
						cout << "Enter an element : ";
						int el;cin >> el;
						l.insertAtBeg(el);
						cout << "Element inserted sucessfully..." << endl;
					}break;
			case 2:{
						cout << "Enter an element : ";
						int el;cin >> el;
						l.insertAtLst(el);
						cout << "Element inserted sucessfully..." << endl;
					}break;
			case 3:{
						cout << "Enter an element to be inserted: ";
						int el;cin >> el;
						cout << "Enter an element AFTER which to be inserted: ";
						int af;cin >> af;
						l.insertAfterN(af,el);
						cout << "Element inserted sucessfully..." << endl;
					}break;
			case 4:{
						cout << "Enter an element to be inserted: ";
						int el;cin >> el;
						cout << "Enter an element BEFORE which to be inserted: ";
						int bef;cin >> bef;
						l.insertBeforeN(bef,el);
						cout << "Element inserted sucessfully..." << endl;
					}break;
			case 5:{
						cout << "Enter an element to be inserted: ";
						int el;cin >> el;
						cout << "Enter the Position: ";
						int pos;cin >> pos;
						l.insertAtN(pos,el);
						cout << "Element inserted sucessfully..." << endl;
					}break;
			case 6:{
						l.display();
						//l.printRec(l.head);
					}break;
			case 7:{
						cout << "Count is: " << l.count();
					}break;
			case 8:{
						cout << "Enter an element to be searched: ";
						int el;cin >> el;
						l.search(el);
					}break;
			case 9:{
						l.deleteBeg();
						cout << "Element Deleted Sucessfully..." << endl;
					}break;
			case 10:{
						cout << "Enter Element to be deleted: ";
						int el; cin >> el;
						l.deleteElement(el);
						cout << "Element Deleted Sucessfully..." << endl;
					}break;
			case 11:{
						l.deleteLst();
						cout << "Element Deleted Sucessfully..." << endl;
					}break;
			case 12:{
						l.reverse();
					}break;
			case 13:{
						l.reverseRec(l.head);
						//l.printRevereRec(l.head);
					}break;
		}
		cout << "q: quit  |  c: continue..." << endl << "=> ";
		cin >> c;cout << endl;		
	}while(c == 'c');
	
	return 0;
}
