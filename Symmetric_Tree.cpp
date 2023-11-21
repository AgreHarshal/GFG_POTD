bool f(Node *r1,Node *r2){
    if(r1!=NULL && r2==NULL || r1==NULL && r2!=NULL){
        return false;
    }
    if(r1==NULL && r2==NULL){
        return true;
    }
    return r1->data==r2->data && f(r1->left,r2->right) && f(r1->right,r2->left);
}
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root==NULL){
	        return true;
	    }
	    return f(root->left,root->right);
    }
};