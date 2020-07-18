/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*void swap(TreeNode* x, TreeNode* y){
    
    //if(!x & !y) {cout<<1<<endl; return;}
    //if(x && y){
        TreeNode* temp = x;
        x = y;
        y = x;
        return;
    /*}
    else if(x){
        y = x;
        x = NULL;
        
    }
    else if(y){
    x = y;
    y = NULL;
    }
    return;
    
}*/
TreeNode* Solution::invertTree(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int cnt = q.size();
        for(int i = 0; i < cnt; i++){
            TreeNode* node = q.front();
            q.pop();
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }
    }
    return A;
}
