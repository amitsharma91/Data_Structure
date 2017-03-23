#include<stdio.h>

struct node{
	int data;
	struct node* link;
};

struct node* addBeg(struct node* start, int data){
	struct node temp;
	temp.data = data;
	temp.link = NULL;
	start = &temp;
	
	return &temp;
}

int main(){
	//create a start of Node
	int data;
	struct node* start;
	start = NULL;
	
	printf("Entere any Data: ");
	scanf("%d",&data);
	start = addBeg(start,data);
		
}
