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

int decimal(Node<int> *head) {
    
    Node<int>* prev=0;
    Node<int>* temp=head;
    Node<int>* next;
    
    while(temp!=0){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;   
    }
    
    head=prev;
    
    int sum=0;
    int p=0;
    
    while(head!=0){
        if(head->data==1){
            sum+=pow(2,p);
        }
        p++;
        head=head->next;
    }
    
    return sum;
    
}


int main() {

	Node<int>* head1 = takeLLInput();
	
	
	cout<<decimal(head1)<<endl;
	
	delete head1;
  
  return 0;
	
}
