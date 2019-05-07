//merge sort recursive
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;
#include "solution.h"
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
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
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* mid(node* head){
    
    if(head==0 || head->next==0){
        return head;
    }
    
    
    node* slow=head;
    node* fast=head->next;
    
    while(fast!=0 && fast->next!=0){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    return slow;
}

node* merg(node* head1, node* head2){
        
    node* finalhead;
    node* finaltail;
    
    if(head1->data>=head2->data){
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
        if(head1->data>=head2->data){
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

node* mergeSort(node *head) {
    
    if(head==0 || head->next==0){
        return head;
    }
    
    node* midpoint=mid(head);
    node* head1=head;
    node* head2=midpoint->next;
    midpoint->next=0;
    
    
    node* finalhead1=mergeSort(head1);
    node* finalhead2=mergeSort(head2);
    
    node* finalhead=merg(finalhead1,finalhead2);
    
    return finalhead;    
}

int main()
{
    node* head=takeinput();
    head= mergeSort(head);
    print(head);
    return 0;
}

