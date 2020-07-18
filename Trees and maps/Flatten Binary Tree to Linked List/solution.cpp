/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 TreeNode* B;
 void func(TreeNode* node){
     //Treenode* B;
     if(node->left){
         TreeNode* temp
         if(node->right){
             
         }
         B->right = new TreeNode(node->left->val);
         //cout<<B->val<<endl;
         B = B->right;
        func(node->left);
     }
     
 }*/
TreeNode* Solution::flatten(TreeNode* A) {
    if(A==NULL) return A;
    //stack<TreeNode*> q;
    //q.push(A);
    //free(B);
    //B = new TreeNode(A->val);
    //TreeNode* C = B;
    //TreeNode* B =  new TreeNode(A->val);
    //TreeNode* c = B;
    if(A->left) {
        TreeNode* temp;
        if(A->right){
            temp = A->right;
        }
        A->right = flatten(A->left);
        A->left = NULL;
        TreeNode* temp2 = A;
        while(temp2->right) temp2 = temp2->right;
        temp2->right = flatten(temp);
    }
    else{
        A->right = flatten(A->right);
    }
    return A;
    /*while(!q.empty()){
        TreeNode* node = q.top();
        q.pop();
        //cout<<B->val<<" "<<node->val<<endl;
        B->right = new TreeNode(node->val);
        //cout<<B->val<<" "<<B->right->val<<endl;
        B = B->right;
        //if(node->left){
            if(node->right)
            q.push(node->right);
            
            //B->right = new TreeNode(node->left->val);
            
            //node->left = NULL;
            //B = B->right;
            //if(node->left->left || node->left->right);
            if(node->left)
            q.push(node->left);
            
            //node = node->right;
            
            //continue;
        //}
        //else{
            //if(node->right){ 
                //B = B->right;
                //if(node->right->left || node->right->right)
              //  q.push(node->right);
            //}
        //}
        
    }
    //
    //func(A);
    return c;*/
}
