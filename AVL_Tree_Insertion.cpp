int heights(Node *root){
      if(root==NULL){
          return 0;
      }
      return root->height;
  }
  int getbalance(Node *root){
      if(root==NULL){
          return 0;
      }
      return (heights(root->left)-heights(root->right));
  }
  Node* left_rotation(Node *root){
      Node* r=root->right;
      Node* rem=root->right->left;
      r->left=root;
      root->right=rem;
      root->height=1+max(heights(root->left),heights(root->right));
      r->height=1+max(heights(r->right),heights(r->left));
     return r;
  }
  Node* right_rotation(Node *root){
      Node* l=root->left;
      Node* rem=l->right;
      l->right=root;
      root->left=rem;
      root->height=1+max(heights(root->left),heights(root->right));
      l->height=1+max(heights(l->left),heights(l->right));
      return l;
  }
class Solution{
  public:
  
    /*You are required to complete this method */
    Node* insertToAVL(Node* root, int data)
    {
        //Your code here
        if(root==NULL){
            return new Node(data);
        }
        if(data>root->data){
            root->right=insertToAVL(root->right,data);
        }else if(data<root->data){
            root->left=insertToAVL(root->left,data);
        }else{
            return root;
        }
        
        root->height=1+max(heights(root->left),heights(root->right));
        int bal=getbalance(root);
        if(bal>1 && data<root->left->data){
            return right_rotation(root);
        }
        if(bal>1 && data>root->left->data){
            root->left=left_rotation(root->left);
            return right_rotation(root);
        }      root->height=1+max(height(root->left),height(root->right));

        if(bal<-1 && data>root->right->data){
            return left_rotation(root);
        }
        if(bal<-1 && data<root->right->data){
            root->right=right_rotation(root->right);
            return left_rotation(root);
        }
        return root;
    }
};