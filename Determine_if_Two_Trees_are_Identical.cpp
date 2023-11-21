bool help(Node *r1,Node *r2){
     if(r1==NULL && r2!=NULL || (r1!=NULL && r2==NULL)){
         return false;
     }
     if(r1==NULL && r2==NULL){
         return true;
     }
     return r1->data==r2->data && (help(r1->left,r2->left)) && help(r1->right,r2->right);
 }
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        return help(r1,r2);
    }
};