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
Node* helper(Node* prev,Node* head,int i,int data){
    if(i>0 && head==NULL){
        return NULL;
    }
    if(i==0 && prev==NULL && head!=NULL){
        Node* ans=new Node(data);
        ans->next=head;
        return ans;
    }
    if(i==0 && prev!=NULL){
        Node* ans=new Node(data);
        prev->next=ans;
        ans->next=head;
        return ans;
    }
    
    Node* ans=helper(head,head->next,i-1,data);
    head->next=ans;
    
    return head;
}

Node* insertNodeRec(Node *head, int i, int data) {
    
    Node* an=helper(NULL,head,i,data);
    
    return an;   
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
    int pos, data;
    cin >> pos >> data;
    head = insertNodeRec(head, pos, data);
    print(head);
    
    return 0;
}
