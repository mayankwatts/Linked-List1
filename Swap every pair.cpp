#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
    	if(next) 
	    delete next;
    }
};

#include "solution.h"

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
    Node*temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* swapEveryPair(Node *head) {
    //write your code here
    
    Node* temph=head;
    Node* temphn=head->next;
    Node* prev=0;
    Node* next;
    
    while(temphn!=0 && temphn->next!=0){
        if(temph==head){
            prev=temph;
            next=temphn->next;
            temph->next=next;
            temphn->next=temph;
            head=temphn;
            temph=temph->next;
            temphn=temph->next;
        }
        else{
        prev->next=temphn;
        next=temphn->next;
        temphn->next=temph;
        temph->next=next;
        prev=temph;
        temph=temph->next;
        temphn=temph->next;
        }
    }
    
    if(temphn!=0){
        prev->next=temphn;
        temphn->next=temph;
        temph->next=0;
    }
    
    return head;

}

int main() {
    Node* head = takeinput();
    head = swapEveryPair(head);
    print(head);
    delete head;
    
    return 0;
}

