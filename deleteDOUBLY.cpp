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
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data"<<val<<endl;
    }
};
void insertAtHead(Node* &head,Node* &tail,int data){
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
    //insertAtstart
    if(i==0){
        insertAtHead(head,tail,data);
        return;
    }
    Node* temp=head;
    int cnt=0;
    while(cnt<i-1){
        cnt++;
        temp=temp->next;
    }
    //insertAtlast
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
void deleteatpos(Node* &head,int pos){
    if(pos==0){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;   
    }else{
        //deleting any middle or last node
        Node* curr=head;
        Node* previous=NULL;
        int cnt=0;
        while(cnt<pos){
            previous=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        previous->next=curr->next;
        curr->next=NULL;
        delete curr;
    }

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
  int n;
  cin>>n;
  while(n--){
      int i,d;
    cin>>i>>d;
        insertAtposition(tail,head,i,d);
  }
cout<<"The linked list is as follows:"<<endl;
    print(head);
    int pos;
    cin>>pos;
    deleteatpos(head,pos);
    print(head);
    return 0;
}
