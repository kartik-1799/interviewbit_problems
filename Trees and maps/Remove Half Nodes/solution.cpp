/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 void check(TreeNode* A){
     if(A->left==NULL && A->right==NULL){
         cout<<A->val<<" this is leaf"<<endl;
         return;
     }
     else if(A->left==NULL){
         cout<<A->val<<" this is half"<<endl;
         check(A->right);
     }
     else if(A->right==NULL){
        cout<<A->val<<" this is half"<<endl; 
        check(A->left);
     }
     else{
         cout<<A->val<<" this is full"<<endl;
         check(A->left);
         check(A->right);
     }
     
 }*/
TreeNode* rem(TreeNode* A){
    if(A==NULL) return A;
    A->left = rem(A->left);
    A->right = rem(A->right);
    if(A->left==NULL&& A->right==NULL){
        return A;
    }
    else if(A->left==NULL){ 
        TreeNode* temp = A->right;
        free(A);
        return temp;
    }
    else if(A->right==NULL){
        TreeNode* temp = A->left;
        free(A);
        return temp;
    } 
    return A;
    
    
}
TreeNode* Solution::solve(TreeNode* A) {
    //TreeNode* B = new TreeNode(A->val);
    //TreeNode* res = NULL;
    //TreeNode* B = res;
    //check(A);
    return rem(A);
    //return res;
    
    
}
