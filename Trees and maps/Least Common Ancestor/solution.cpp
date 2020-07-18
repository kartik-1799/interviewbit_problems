/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int func(TreeNode* node, int &B, int &C){
     if(node==NULL) return 0;
     int x1 = 0, x2 = 0;
     if(node->left)
     x1 = func(node->left, B, C);
     if(node->right)
     x2 = func(node->right, B, C);
     //cout<<x1<<" "<<x2<<" "<<node->val<<endl;
     if(x1>0&&x2>0){
         B = node->val;
         return -1;
     }
     if(x1==0 && x2==0){
         if(node->val==B) return 1;
         if(node->val==C) return 2;
         return 0;
     }
     if(x1==1 || x2==1){
        if(node->val==C){ 
            B = node->val;
            return  -1;
        }
        B = node->val;
        return 1;
     }
     if(x1==2 || x2==2){
         if(node->val==B) return -1;
         C = node->val;
         return 2;
     }
     return -1;
 }
int Solution::lca(TreeNode* A, int B, int C) {
    if(A==NULL) return -1;
    
    
    int res = -1;
    int f = 0;
    if(B==C){
        if(A->val==B) return A->val;
        queue<TreeNode*> q;
        q.push(A);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            //cout<<node->val<<" "<<q.size()<<endl;
            if(node->left){
                if(node->left->val==B) return B;
                else q.push(node->left);
            }
            if(node->right){
                if(node->right->val==B) return B;
                else q.push(node->right);
            }
        }
        return -1;
    }
    if(A->val==B||A->val==C){
        f = 1;
        res = A->val;
        //if(B==C) return res;
        queue<TreeNode*> q;
        q.push(A);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                if(node->left->val==B||node->left->val==C) return res;
                else q.push(node->left);
            }
            if(node->right){
                if(node->right->val==B||node->right->val==C) return res;
                else q.push(node->right);
            }
        }
        return -1;
    }
    if(func(A, B, C)==-1){
        return B;
    }
    
    
    return -1;
}
