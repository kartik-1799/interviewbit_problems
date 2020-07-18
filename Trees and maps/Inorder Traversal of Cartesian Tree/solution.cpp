int func(vector<int> &A, int i, int n){
    if(i>n) return -1;
    int pos = i;
    int m= A[i++];
    
    while(i <= n){
        if(A[i]>m){
            m = A[i];
            pos = i;
        }
        i++;
    }
    return pos;
}

TreeNode*  cartesian( int start, int end, vector<int> &A){
    if(start>end) return NULL;
    int i = func(A, start, end);
    
    TreeNode* root = new TreeNode(A[i]);
    root->left = cartesian( start, i-1, A);
    root->right = cartesian( i+1, end, A);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    //sort(A.begin(), A.end());
    int n = A.size();
    TreeNode* res;
    if(n==0) return res;
    int i = func(A, 0, n-1);
    
    res = new TreeNode(A[i]);
    res->left = cartesian(0, i-1, A);
    res->right = cartesian(i+1, n-1, A);
    
    
    //cartesian(res, 0, n-1, A);
    return res;
}
