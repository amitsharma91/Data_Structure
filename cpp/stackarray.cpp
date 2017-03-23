#include<iostream>
using namespace std;

class StackArray{
	public:	
	static const int MAX = 10;
	int arr[MAX];
	int top;
	StackArray():top(-1){}

	void push(int);
	void pop();
	int getTop();
	bool isEmpty();
	int size();
	void display();
};

void StackArray::push(int data){
	if(top == MAX-1){
		cout << "ERROR: stack overflow" << endl;
		return;
	}
	arr[++top] = data;
}

void StackArray::pop(){
	if(isEmpty()){
		cout << "No Elements to pop. Stack is Empty" << endl;
		return;
	}
	if(top>-1)		
	top --;
}

int StackArray::getTop(){
	if(isEmpty()){
		cout << "No Elements to pop. Stack is Empty" << endl;
	}
	return arr[top];
}

bool StackArray::isEmpty(){
	if(top == -1)
		return true;
	else
		return false;
}

int StackArray::size(){
	if(isEmpty())
		return 0;
	else
		return top+1;
}

void StackArray::display(){
	cout << "Element in Stack are: " << endl;	
	for(int i=0;i<=top;i++)
		cout << arr[i] << " --> ";
	cout << endl;
}

int main(){
	StackArray s;
	while(true){
		cout << "\n1: PUSH\n2: POP\n3: TOP\n4: Is Empty?\n5: Size\n6: Dispaly" << endl;
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
						if(s.isEmpty())
							cout << "Stack is Empty" << endl;
						else
							cout << "Stack is NOT Empty" << endl;								 		
					}break;
			case 5:{
						cout << "Elements in Stack are: " << s.size() << endl;
					}break;
			case 6:{
						s.display();
					}break;
		}
	}
	return 0;
}
