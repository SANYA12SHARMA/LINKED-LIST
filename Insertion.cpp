#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
Node* input(){
    int d;
    cin>>d;
    Node* head=NULL;
    Node* tail=NULL;
    while(d!=-1){
        Node* newn=new Node(d);
        if(head==NULL){
           head=newn;
           tail=newn;
        }else{
            tail->next=newn;
            tail=newn;
        }
        cin>>d;
    }
    return head;
}
Node* insert(Node* head,int i,int data){
    Node* insertinto=new Node(data);
    if(i==0){
         insertinto->next=head;
         return insertinto;
    }
    int cnt=0;
    Node* ptr=head;
    while(ptr){
        if(cnt==i-1){
            insertinto->next=ptr->next;
            ptr->next=insertinto;
            return head;
        }
        cnt++;
        ptr=ptr->next;
    }
    if(ptr==NULL){
        return head;
    }
   
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
int main()
{
    Node* head=input();
    print(head);
    int i,d;
    cin>>i>>d;
    head=insert(head,i,d);
    print(head);
    int s;
    cin>>s;
    head=delet(head,s);
    print(head);
    return 0;
}
