#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;
#include "Solution.h"

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

Node* mergeTwoLLs(Node *head1, Node *head2) {
    
    Node* finalhead;
    Node* finaltail;
    
    if(head1->data>head2->data){
        finalhead=head2;
        finaltail=head2;
        head2=head2->next;
    }
        
    else{
        finalhead=head1;
        finaltail=head1;
        head1=head1->next;
    }
       
    while(head1!=0 && head2!=0){
        if(head1->data>head2->data){
            finaltail->next=head2;
            finaltail=head2;
            head2=head2->next;
        }
        
        else{
            finaltail->next=head1;
            finaltail=head1;
            head1=head1->next;
        }
    }
    
    if(head2==0)
        finaltail->next=head1;
    else
        finaltail->next=head2;
    
    return finalhead; 
}

int main() {
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}

