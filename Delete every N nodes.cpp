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

node* skipMdeleteN(node  *head, int M, int N) {
    
    node* temp=head;
    node* prev;
    int flag=0;
    
    while(temp!=0){
        
        for(int i=0;i<M;i++){
            if(temp==0)
                break;
            prev=temp;
            temp=temp->next;
        }
        
        
        
        for(int j=0;j<N;j++){
            if(temp==0){
                flag=1;
               break; 
            }
                
            temp=temp->next;
        }
        if(flag==0)
        prev->next=temp;
        
        else
            prev->next=0;
        
        if(temp==0)
            break;      
        
    }
    
    return head;

}

int main()
{
    node* head=takeinput();
    int m,n;
    cin>>m >> n;
    head= skipMdeleteN(head,m,n);
    print(head);
    return 0;
}
