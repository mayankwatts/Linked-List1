#include <iostream>
using namespace std;

template <typename T>
class ListNode {
    public:
    T data;
    ListNode<T> *next;
    ListNode<T>(T data)
    {
        this -> data=data;
        next = NULL;
    }
};

#include "solution.h"

 ListNode<int>* createlist()
	{
	    ListNode<int> *head=NULL;
		ListNode<int> *rear=NULL;
		int data;
		cin>>data;
		while(data!=-1)
		{
			ListNode<int> *newnode=new ListNode<int>(data);
			if(head==NULL)
			{
				head=newnode;
				rear=head;
			}
			else
			{
				rear->next=newnode;
				rear=rear->next;
			}
			cin>>data;
		}
		return head;
	}

    void print(ListNode<int> * head)
	{
		while(head!=NULL)
		{
			cout<<head->data<<endl;
			head=head->next;
		}
	}

ListNode<int> *unionOf2LL(ListNode<int> *head1,ListNode<int> *head2)
	{
	    //WRITE YOUR CODE HERE
       ListNode<int>* last;
       ListNode<int>* temp1=head1;
       ListNode<int>* temp2;
       ListNode<int>* prev;
       
       while(temp1->next!=0){
           temp1=temp1->next;
       }
       last=temp1;
       temp1=head1;
       
       while(temp1!=0){
           
           temp2=head2;
           prev=0;
           
           while(temp2!=0){
               if(head2->data==temp1->data){
                   head2=head2->next;
                   break;
               }
               else if(temp2->data==temp1->data){
                   prev->next=temp2->next;
                   break;
               }
               else{
                   prev=temp2;
                   temp2=temp2->next;
               }     
           }
           
           temp1=temp1->next; 
           
       }
       
       last->next=head2;
       
       return head1;
       
	}

int main()
{
   ListNode<int> *head1=createlist();
   ListNode<int> *head,*head2=createlist();
   head=unionOf2LL(head1,head2);
   print(head);
}
