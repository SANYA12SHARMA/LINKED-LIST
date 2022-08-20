#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};
void insertAtHead(Node* &tail,Node* &head,int data){
    
    if(head==NULL){
        Node* newnode=new Node(data);
        head=newnode;
        tail=newnode;
    }else{
        Node* newnode=new Node(data);
        newnode->next=head;
    head->prev=newnode;
    head=newnode;
    }
}
void insertAtTail(Node* &tail,Node* &head,int data){
    
    if(tail==NULL){
        Node* newnode=new Node(data);
        tail=newnode;
        head=newnode;
    }else{
        Node* newnode=new Node(data);
            tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    }

}
void insertAtposition(Node* &tail,Node* &head,int i,int data){
    //insert at start
    if(i==1){
        insertAtHead(tail,head,data);
        return ;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<i-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,head,data);
        return;
    }

    Node* newnode=new Node(data);
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
    
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    insertAtHead(tail,head,13);
    insertAtHead(tail,head,12);
    insertAtHead(tail,head,8);
    print(head);
    insertAtTail(tail,head,25);
    print(head);
    int i;
    cin>>i;
    insertAtposition(tail,head,i,267);
    print(head);
    return 0;
}
