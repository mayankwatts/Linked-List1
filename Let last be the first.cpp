//Move last element to front of a given Linked List
#include<iostream>
using namespace std;

template <typename T>
class Node {
	public:
	T data;
	Node* next;

	Node(T data) {
		next = NULL;
		this->data = data;
	}

	~Node() {
		if (next != NULL) {
			delete next;
		}
	}
};

#include"solution.h"


Node<int>* takeLLInput() {
    int data;
    cin>>data;
    Node<int>* head=NULL,*tail=NULL;
    while(data!=-1){
        Node<int> *newnode=new Node<int>(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}

void printLL(Node<int>*  head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

Node<int>* moveToFront(Node<int> *head_ref) {
	// Write your code here
    Node<int>* temp=head_ref;
    Node<int>* head=head_ref;
    Node<int>* prev;
    
    while(temp->next!=0){
        prev=temp;
        temp=temp->next; 
    }
    prev->next=0;
    temp->next=head;
    head=temp;
    
    return head;
    
}

int main() {

	Node<int>* head = takeLLInput();
	head = moveToFront(head);
	printLL(head);
	delete head;
  
  return 0;
  
}
