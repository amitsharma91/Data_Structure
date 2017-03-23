/*
 */

#include<iostream>
#include<stdlib.h>
using namespace std;

class sparse {
	int r;          // row number
	int c;          // column number
	sparse *rptr;   // row pointer
	sparse *cptr;   // column header
	int data;       // actual data
public:
	sparse * create(sparse*);
	void display(sparse*);
	void add(sparse*, sparse*);
};

sparse * sparse::create(sparse*h) {
	cout << "Enter the no. of rows :: ";
	cin >> r;
	cout << "Enter the no. of Columns:: ";
	cin >> c;
	// create the head node
	h = new sparse;
	h -> r = r;
	h -> c = c;
	h -> rptr = h;
	h -> cptr = h;
	h -> data = 0;
	// create column headers
	sparse *ptr;
	int i, j, d;
	ptr = h;
	for (i = 1; i <= c; i++) {
		sparse *node;
		node = new sparse;
		node ->r = 0;
		node -> c = i;
		node -> data = 0;
		node -> rptr = h;
		node -> cptr = node;
		ptr -> rptr = node;
		ptr = node;
	}
	// create row headers
	ptr = h;
	for (i = 1; i <= r; i++) {
		sparse *node;
		node = new sparse;
		node -> r = i;
		node -> c = 0;
		node -> data = 0;
		node -> rptr = node;
		node -> cptr = h;
		ptr -> cptr = node;
		ptr = node;
	}
	cout << endl << "Now enter the non zero elements one by one: " << endl;
	cout << "Enter row number,column number,data" << endl;
	cout << "Enter (0 0 0) to stop ::";
	cin >> i >> j >> d;
	if (i > r || j > c || i < 1 || j < 1) {
		cout << " error input";
		exit(1);
	}
	while (i && j && d) {
		sparse * row_header = h -> cptr;
		sparse * column_header = h -> rptr;
		// find the correct row header and column header
		while (row_header -> r < i)
			row_header = row_header -> cptr;
		while (column_header -> c < j)
			column_header = column_header -> rptr;
		sparse *ptr1;
		sparse *ptr2;
		// find the correct position to insert
		sparse*row_ptr = row_header;
		while (row_ptr ->c < j) {
			ptr1 = row_ptr;
			row_ptr = row_ptr ->rptr;
			if (row_ptr == row_header)
				break;
		}
		sparse*column_ptr = column_header;
		while (column_ptr -> r < i) {
			ptr2 = column_ptr;
			column_ptr = column_ptr ->cptr;
			if (column_ptr == column_header)
				break;
		}
		sparse *node;
		node = new sparse;
		node -> r = i;
		node -> c = j;
		node -> data = d;
		ptr1 -> rptr = node;
		ptr2 -> cptr = node;
		node -> rptr = row_ptr;
		node -> cptr = column_ptr;
		 cout << "Enter row number,column number,data" << endl;
		cout << "Enter (0 0 0) to stop ::";
		cin >> i >> j >> d;
		if (i > r || j > c) {
			cout<< "error input";
			exit(1);
		}
	}
	return h;
}

void sparse::display(sparse*h) {
	sparse *right;
	right = h -> cptr;

	while (right != h) {
		sparse *r = right;
		right = right ->rptr;
		while (right != r) {
			cout << right -> r << "\t" << right-> c << "\t" << right -> data << endl;
			right = right ->rptr;
		}
		right = right ->cptr;
	}
}

void sparse::add(sparse*h1, sparse*h2) {
	if(h1 -> r == h2 -> r && h1 -> c == h2 -> c)
		 cout << "The addition of the two given "
		   <<" sparse matrices is ::\n";
	else
	{
		cout << "addition is not possible";
		exit(1);
	}
	sparse *r1;
	r1 = h1 ->cptr;
	sparse *r2;
	r2 = h2 ->cptr;

	while (r1 != h1) {
		sparse * p1 = r1;
		r1 = r1 ->rptr;
		sparse * p2 = r2;
		r2 = r2 ->rptr;
		while (r1 != p1 && r2 != p2) {
			if (r1 ->c == r2 ->c) {
				cout << r1 -> r << "\t" << r1 -> c << "\t" << (r1 -> data + r2 -> data) << endl;
				r1 = r1 ->rptr;
				r2 = r2 ->rptr;
			} else if (r1 ->c > r2 ->c) {
				cout << r2 -> r << "\t" << r2 -> c << "\t" << r2 -> data << endl;
				r2 = r2 ->rptr;
			} else {
				cout << r1 -> r << "\t" << r1 -> c << "\t" << r1 -> data << endl;
				r1 = r1 ->rptr;
			}
		}
		while (r1 != p1) {
			cout << r1 ->r << "\t" << r1 ->c << "\t" <<r1 ->data << endl;
			r1 = r1 ->rptr;
		}
		while (r2 != p2) {
			cout << r2 ->r << "\t" << r2 ->c << "\t" <<r2 ->data << endl;
			r2 = r2 ->rptr;
		}
		r1 = r1 ->cptr;
		r2 = r2 ->cptr;
	}
}

int main(){
	cout<<"******************************************";
	cout<<"\nThis program is to perform addition of \n";
	cout<< " two sparse matrices \n";
	cout<< "*******************************************\n";
	sparse s;
	sparse *h1 = NULL, *h2 = NULL;
	cout<<"Enter the values for sparse matrix 1 ::\n";
	 cout<<"****************************************\n";
	h1 = s.create(h1);
	s.display(h1);
	cout<<"Enter the values for sparse matrix 2 ::\n";
	cout<<"****************************************\n";
	h2 = s.create(h2);
	s.display(h2);
	s.add(h1, h2);
	return 0;
}

/*
	OUTPUT:
	
	developeramit@localhost:~/Assignment/DS$ ./a.out
	******************************************
	This program is to perform addition of 
	 two sparse matrices 
	*******************************************
	Enter the values for sparse matrix 1 ::
	****************************************
	Enter the no. of rows :: 2
	Enter the no. of Columns:: 2

	Now enter the non zero elements one by one: 
	Enter row number,column number,data
	Enter (0 0 0) to stop ::0
	0
	6
	 error inputdeveloperamit@localhost:~/Assignment/DS$ ^C
	developeramit@localhost:~/Assignment/DS$ 
*/
