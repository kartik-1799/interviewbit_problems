vector<int> Solution::solve(vector<int> &A, int B) { 
    priority_queue <int, vector<int>, greater<int>> gquiz;
    for(int i =0; i < A.size(); i++){
        if(gquiz.size() < B) gquiz.push(A[i]);
        else{
            if(gquiz.top() < A[i]){
                gquiz.pop();
                gquiz.push(A[i]);
            }
        }
    }
    vector<int> v;
    while(!gquiz.empty()){
        v.push_back(gquiz.top());
        gquiz.pop();
    }
    return v;
}
