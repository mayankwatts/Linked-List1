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
Node* deleteNode(Node *head, int i) {
    
    Node* prev=NULL;
    Node* temp=head;
    
    while(i && temp!=NULL){
        prev=temp;
        temp=temp->next;
        i--;
    }
    
    if(temp!=NULL && prev!=NULL){
        prev->next=temp->next;
        temp->next=NULL;
    }
    
    else if(prev==NULL){
        head=head->next;
        temp->next=NULL;
    }
    else{
        
    }
    delete temp;
    
    return head;
}

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

int main() {
    Node *head = takeinput();
    int pos;
    cin >> pos;
    head = deleteNode(head, pos);
    print(head);
    
    return 0;
}
