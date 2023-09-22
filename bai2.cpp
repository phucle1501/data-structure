#include <iostream>
using namespace std;

struct node {
	int data;
	node*next;
	node(int val) : data(val),next(NULL) {}
};

node* insert(node*head,int position,int x)
 {
 	node* newnode = new node(x);
 	if(position ==0 || head==NULL) {
 		newnode->next=head;
 		return newnode;
	 }
	 node*current=head;
	 int count=0;
	 while (count <position -1 && current ->next !=NULL) {
	 	current = current->next;
	 	count++;
	 }
	 newnode->next=current->next;
	 current->next=newnode;
	 return head;
 }
 
 node *deletenode(node* head,int position) {
 	if(position ==0) {
 		node*temp=head;
 		head=head->next;
 		delete temp;
 		return head;
	 }
	 node* current=head;
	 int count=0;
	 while (count <position -1 && current ->next !=NULL) {
	 	current = current ->next;
	 	count++;
	 }
	 if(current ->next ==NULL) {
	 	return head;
	 }
	 node*temp=current ->next;
	 current ->next=current ->next->next;
	 delete temp;
	 return head;
 }
 
 void printlist(node*head) {
 	while (head !=NULL) {
 		cout<<head ->data<<" ";
 		head=head->next;
	 }
 }
 
 int main() {
 	int n;
 	cin>>n;
 	node*head=NULL;
 	for (int i=0;i<n;i++) {
 		string operation;
 		cin>>operation;
 		if(operation == "insert") {
 			int p,x;
 			cin>>p>>x;
 			head=insert(head,p,x);
		 }
		 else if (operation == "delete") {
		 	int p;
		 	cin>>p;
		 	head=deletenode(head,p);
		 }
	 }
	 printlist(head);
	 return 0;
 }
