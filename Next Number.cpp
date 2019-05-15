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

int increment(Node* head){
    if(head->next==0){
        if(head->data==9){
            head->data=0;
            return 1;
        }
        else{
            head->data+=1;
            return 0;
        }
    }
    
    int car=increment(head->next);
    
    head->data+=car;
    
    if(head->data>9){
        head->data=0;
        return 1;
    }
    
    else{
        return 0;
    }
    
}

Node* NextLargeNumber(Node *head) {
    
    int car=increment(head);
    
    if(car==0)
        return head;
    else{
        Node* newnode= new Node(1);
        newnode->next=head;
        return newnode;
    }
    
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    
    return 0;
}
