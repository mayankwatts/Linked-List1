//head is the head of you linked list
// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
bool check_palindrome(node* head)
{
    int count=1;
    
    node *temp=head;
    while(temp->next!=0){
        count++;
        temp=temp->next;
    }
    
    int n=(count+1)/2;
    
    node* head1=head;
    for(int i=0;i<n;i++){
        head1=head1->next;
    }
    
    node* head2=head1;
    node* next;
    node* prev=0;
    for(int i=0;i<count-n;i++){
        next=head2->next;
        head2->next=prev;
        prev=head2;
        head2=next; 
    }
    head1=head;
    head2=prev;
    for(int i=0;i<count-n;i++){
        if(head1->data==head2->data){
            head1=head1->next;
            head2=head2->next;
        }
        else
            return false;
    }
    
    return true;
}
