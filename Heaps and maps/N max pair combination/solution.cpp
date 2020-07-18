typedef pair<int, int> pii;
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    A.push_back(INT_MIN);
    B.push_back(INT_MIN);
    sort(A.begin(), A.end(), greater());
    sort(B.begin(), B.end(), greater());
    
    priority_queue <pair<int, pii>> pqe;
    set<pii> visited;
    vector<int> ans;
    
    pqe.push({A[0]+B[0], {0,0}});
    visited.insert({0,0});
    while(ans.size()<n){
        pair<int, pii> c = pqe.top();
        pqe.pop();
        ans.push_back(c.first);
        int x = c.second.first, y = c.second.second;
        //cout<<x<<" "<<y<<endl;
        if(visited.find({x, y+1})==visited.end())
        visited.insert({x, y+1}), pqe.push({A[x]+B[y+1],{x, y+1}});
        if(visited.find({x+1, y})==visited.end())
        visited.insert({x+1, y}), pqe.push({A[x+1]+B[y], {x+1, y}});
    }
    
    return ans;
    
}
