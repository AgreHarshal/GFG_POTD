class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        Node *temp=head;
        while( temp->next!=NULL){
            Node *temp2=temp->next;
            temp->next=temp->prev;
            temp->prev=temp2;
            temp=temp2;
        }
        temp->next=temp->prev;
        temp->prev=NULL;
        return temp;
    }
};
