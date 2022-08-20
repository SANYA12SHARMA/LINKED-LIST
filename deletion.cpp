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

Node* delet(Node* head,int i){
    if(i==0){
        if(head==NULL){
            return NULL;
        }
        return head->next;
    }
    Node* ptr=head;
    int count=0;
    while(ptr){
        if(count==i-1){
            ptr->next=ptr->next->next;
            return head;
        }
        if(ptr->next==NULL){
            return NULL;
        }
        count++;
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
    int s;
    cin>>s;
    head=delet(head,s);
    print(head);
    return 0;
}
