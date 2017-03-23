/*
 	Palindrome.cpp
 */
#include <string>

#include <iostream>
#define STACKSIZE 80
#define TRUE 1
#define FALSE 0
using namespace std;

class Stack {
public:
	void StackInit();
	int IsStackEmpty();
	int IsStackFull();
	int StackPush(char c);
	char StackPop();
	char ViewStackTop();
private:
	char myStack[80];
	int top;
};
string pstring;

int main() {
	// write your code here
	cout << "This Is A Palindrome Check Programe" << endl;
	cout << "Please Enter Anything For Palindrome Check" << endl;
	cin >> pstring;
	system("pause");
	return 0;
}
void Stack::StackInit() {
	top = -1;
}
int Stack::IsStackEmpty() {
	if (top == -1)
		return TRUE;
	return FALSE;
}
int Stack::IsStackFull() {
	if (top == (STACKSIZE - 1))
		return TRUE;
	return FALSE;
}
int Stack::StackPush(char c) {
	if (top == (STACKSIZE - 1))
		return FALSE;
	myStack[++top] = c;
	return TRUE;
}

char Stack::StackPop() {
	if (top == -1)
		return '\0';
	return myStack[top--];
}
char Stack::ViewStackTop() {
	if (top == -1)
		return '\0';
	return myStack[top];
}
