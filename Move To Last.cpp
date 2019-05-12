#include <iostream>
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

Node<int>* func(Node<int> *head,int n) {
    	
    Node<int>* temphead=head;
    Node<int>* tail;
    Node<int>* temptail;
    Node<int>* prev=0;
    
    while(temphead->next!=0){
        temphead=temphead->next;
    }
    tail=temphead;
    temptail=tail;
    temphead=head;
    int flag=0;
    
    while(temphead!=tail->next){
        
        
        if(temphead==head && temphead->data==n){
            if(tail==temphead)
                flag=1;
            temptail->next=temphead;
            temptail=temptail->next;
            head=head->next;
            temphead=head;
            temptail->next=0;
            if(flag==1)
                return head;
            
        }
        
        else if(temphead->data==n){
            temptail->next=temphead;
            temptail=temptail->next;
            prev->next=temphead->next;
            temptail->next=0;
            if(temphead==tail)
                return head;
            temphead=prev->next;
            
            
        }
        
        else{
            prev=temphead;
            temphead=temphead->next;
        }
        
    }
    
    return head;
    
}

int main() {

	Node<int>* head1 = takeLLInput();
	int n;
	cin>>n;
	printLL(func(head1,n));	
	delete head1;
	
}
