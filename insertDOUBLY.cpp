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
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
// int getlen(Node* head){
//     int len=0;
//     Node* temp=head;
//     while(temp!=NULL){
//         len++;
//         temp=temp->next;
//     }
//     return len;
// }
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
        print(head);
    }
    
    int position,d;
    cin>>position>>d;
    insertatpos(head,tail, position,d);
    print(head);
    return 0;
}
