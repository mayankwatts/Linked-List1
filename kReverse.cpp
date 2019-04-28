//Implement kReverse(int k) i.e. you reverse first k elements then reverse next k elements and so on
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

node* kReverse(node*head,int n)
{
   int count=0;
    node* temp=head;
    node* prev;
    node* next;
    
    while(temp!=0){
        temp=temp->next;
        count++;
    }
    if(n>count){
        temp=head;
        prev=0;
        for(int i=0;i<count;i++){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;   
        }
        head=prev;
        return head;  
    }
    else{
        int k=count/n;
        int m=count%n;
        node* finalhead;
        
        prev=0;
        temp=head;
        node* temphead;
        node* extra;
        for(int i=0;i<k;i++){
            temphead=temp;
            prev=0;
            for(int j=0;j<n;j++){
                next=temp->next;
                temp->next=prev;
                prev=temp;
                if(i>0 && j==n-1)
                    extra->next=temp;
                temp=next;
            }
            if(i==0){
                finalhead=prev;
            }
            extra=temphead;
            
        }
        
        if(m>0){
            prev=0;
            for(int i=0;i<m;i++){
                next=temp->next;
                temp->next=prev;
                prev=temp;
                if(i==m-1)
                    extra->next=temp;
                temp=next;  
        }
        }
    
       return finalhead; 
        
    }
    
}

int main()
{
    node* head=takeinput();
    int n;
    cin>>n;
    head=kReverse(head,n);
    print(head);
    return 0;
}
