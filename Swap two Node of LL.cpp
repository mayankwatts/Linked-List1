//Implement code to swap two elements of a Linked List. You need to swap the nodes not the data
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

node* swap_nodes(node *head,int i,int j)
{
    
    int count=0;
    node* temp=head;
    node* tempi;
    node* tempj;
    node* previ;
    node* prevj;
    while(temp!=0){
        if(count==i){
            tempi=temp;
        }
        if(count==j){
            tempj=temp;
        }
        if(count+1==i){
            previ=temp;
        }
         if(count+1==j){
            prevj=temp;
        }
        
        temp=temp->next;
        count++;
    }
    
    if(i!=0 && j!=0){
    previ->next=tempj;
    prevj->next=tempi;
    temp=tempi->next;
    tempi->next=tempj->next;
    tempj->next=temp;
    }
    
    if(i==0){
    head=tempj;
    prevj->next=tempi;
    temp=tempi->next;
    tempi->next=tempj->next;
    tempj->next=temp; 
    }
    
    if(j==0){
    head=tempi;
    previ->next=tempj;
    temp=tempi->next;
    tempi->next=tempj->next;
    tempj->next=temp;  
    }
  
    return head;  
}

int main()
{
    int i,j;
    node* head =takeinput();
    cin>>i;
    cin>>j;
    head=swap_nodes(head,i,j);
    print(head);
    return 0;
}

