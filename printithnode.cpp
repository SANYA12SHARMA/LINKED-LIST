void printIthNode(Node* head, int pos){
    Node* temp=head;
    int j=0;
    while(temp!=NULL){
        temp=temp->next;
        j++;
        if(pos==j){
            cout<<temp->data<<" ";
        }
    }
}
