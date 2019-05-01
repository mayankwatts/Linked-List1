#include<iostream>
using namespace std;

template <typename T>
class Node {
	public:
	T data;
	Node* next;

	Node(T data) {
		next = NULL;
		//(*this).data = data;
		this->data = data;
	}

	~Node() {
		if (next != NULL) {
			delete next;
		}
	}
};

Node<int>* takeLLInput() {
    int data;
    cin>>data;
    Node<int>* head=NULL,*tail=NULL;
    while(data!=-1){
        Node<int> *newnode=new Node<int>(data);
        if(head==NULL) {
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

void printL(Node<int>*  head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void AlternatingSplit(Node<int>* head) {
    
    Node<int>* head1=head;
    Node<int>* head2=head->next;
    Node<int>* temp1=head;
    Node<int>* temp2=head->next;

	// Write your code here
    while(head1->next!=0 && head2->next!=0){
        
        head1->next=head2->next;
        head1=head2->next;
        head2->next=head1->next;
        head2=head1->next;
    }
    head1->next=0;
    
    Node<int>* prev=0;
    Node<int>* next;
    
    while(temp1!=0){
        
        next=temp1->next;
        temp1->next=prev;
        prev=temp1;
        temp1=next;  
    }
    temp1=prev;
    
    prev=0;
    while(temp2!=0){
        
        next=temp2->next;
        temp2->next=prev;
        prev=temp2;
        temp2=next;  
    }
    temp2=prev;
    
    
    
    printL(temp1);
    printL(temp2);
    
}

int main()
{ 
	Node<int>* head=takeLLInput();

	AlternatingSplit(head);
	
}
