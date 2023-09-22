#include <iostream>
using namespace std;

class node {
public: 
	int data;
	node*next;
	
	node(int data) {
		this->data=data;
		this->next=NULL;
	}
};

class linkedlist {
	private:
		int n;
	public:
		node*head;
		linkedlist() {
			n=0;
			head=NULL;
		}
	void insertnode(int pos,int data) {
		node* newnode = new node(data);
		if(pos ==0) {
			newnode ->next=head;
			head= newnode;
		}
		else if (pos==n) {
			node*prevnode = head;
			while (prevnode->next!=NULL) {
				prevnode=prevnode->next;
			}
			prevnode ->next= newnode;
		}
		else {
			node*prevnode=head;
			for (int i=0;i<=pos;i++) {
				prevnode=prevnode->next;
			}
			node* nextnode =prevnode->next;
			
			newnode->next=nextnode;
			prevnode->next=newnode;
		}
		n++;
	}
	
	void deletenode(int pos) {
		if(pos==0) {
			head=head->next;
		}
		else if (pos==n) {
			node*prevnode = head;
			while(prevnode->next !=NULL) {
				prevnode=prevnode->next;
			}
			prevnode->next=NULL;
		}
		else {
			node*prevnode=head;
			for (int i=0;i<pos;i++) {
				prevnode=prevnode->next;
			}
			prevnode->next=prevnode->next->next;
		}
		n--;
	}
	
	void print() {
		node* Node=head;
		while(Node !=NULL) {
			cout<<Node->data<<" ";
			Node=Node->next;
		}
		cout<<endl;
	}
};

int main() {
	int n;
	cin>>n;
	linkedlist l;
	while(n--) {
		string method;
		int p,x;
		cin>>method;
		if(method == "insert") {
			cin>>p>>x;
			l.insertnode(p,x);
		}
		else if (method == "delete") {
			cin>>p;
			l.deletenode(p);
		}
	}
	l.print();
	return 0;
}
