#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
             next=NULL;
        }
        cout<<"memory free for node with data"<<val<<endl;
    }
};
void insertathead(Node* &head,Node* &tail,int d){
    if(head==NULL){
        Node* newnode=new Node(d);
        head=newnode;
        tail=newnode;
    }else{
    Node* newnode=new Node(d);
    newnode->next=head;
    head->prev=newnode;
    head=newnode;}
}
void insertattail(Node* &head,Node* &tail,int d){
    if(head==NULL){
        Node* newnode=new Node(d);
        head=newnode;
        tail=newnode;
    }else{
    Node* newnode=new Node(d);
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;}
}
void insertatpos(Node* &head,Node* &tail,int position,int d){
    if(position==0){
        insertathead(head,tail,d);
        return;
    }
    Node* temp=head;
    int cnt=0;
    while(temp && cnt<position-1){
        cnt++;
        temp=temp->next;
    }
    if(temp->next==NULL){
        insertattail(head,tail,d);
        return;
    }
        Node* newnode=new Node(d);
        newnode->next=temp->next;
        temp->next->prev=newnode;
        newnode->prev=temp;
        temp->next=newnode;
}
void delhead(Node* &head,int position){
    if(position==0){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }else{
           Node* curr=head;
    Node* prev=NULL;
    int cnt=0;
    while(cnt<position){
        cnt++;
        prev=curr;
        curr=curr->next;
    }
    curr->prev=NULL;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr; 
    }

}
void print(Node* &head){
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
    // cout<<getlen(head)<<endl;
    int n;
    cin>>n;
    while(n--){
        int d;
        cin>>d;
        insertattail(head,tail,d);
    }
    int position,d;
    cin>>position>>d;
    insertatpos(head,tail, position,d);
    print(head);
    int pos;
    cin>>pos;
    delhead(head,pos);
    print(head);
    return 0;
}
