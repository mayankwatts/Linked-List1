//Arrange elements in a Linked List such that all even numbers are placed after odd numbers
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

node* arrange_LinkedList(node* head)
{
    //write your code here
    node* temphead=head;
    node* tail;
    
    while(temphead->next!=0){
        temphead=temphead->next;
    }
    tail=temphead;
    temphead=head;
    
    node* temptail=tail;
    node* prev=0;
    int flag=0;
    
    while(temphead!=tail->next){
        if(temphead==head && temphead->data%2==0){
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
        else if((temphead->data)%2==0){
            prev->next=temphead->next;
            temptail->next=temphead;
            temptail=temptail->next;
            temptail->next=0;
            if(tail==temptail)
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

int main()
{
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}
