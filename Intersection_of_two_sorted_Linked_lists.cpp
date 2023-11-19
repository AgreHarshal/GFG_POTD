class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        Node *head=NULL;
        Node *prev=NULL;
        Node *temp1=head1;
        Node *temp2=head2;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->data==temp2->data){
                Node *new_node=new Node(temp1->data);
                if(prev==NULL){
                    head=new_node;
                    prev=head;
                }else{
                    prev->next=new_node;
                    prev=new_node;
                }
                temp1=temp1->next;
                temp2=temp2->next;
            }else if(temp1->data>temp2->data){
                temp2=temp2->next;
            }else{
                temp1=temp1->next;
            }
        }
        return head;
        
    }
};
