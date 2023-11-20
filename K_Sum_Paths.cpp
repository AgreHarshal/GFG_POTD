#define mod 1000000007
unordered_map<int,int>mp;
int res=0;
void f(Node *root,int k,int &sum){
    if(root==NULL){
        return ;
    }
    int val=root->data;
    sum+=val;
    if(mp.find(sum-k)!=mp.end()){
        res=res+mp[sum-k];
        res%=mod;
    }
    mp[sum]++;
    f(root->left,k,sum);
    f(root->right,k,sum);
    mp[sum]--;
    if(mp[sum]==0){
       mp.erase(sum);  
    }
    sum-=val;
}
class Solution{
  public:
    int sumK(Node *root,int k)
    {
        // code here
        res=0;
        int sum=0;
        mp.clear();
        mp[0]++;
        f(root,k,sum);
        return res;
    }
};