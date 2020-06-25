void heapPermutation(vector<vector<int>>& ans, vector<int>& a, int s, int n) 
{ 
    // if size becomes 1 then prints the obtained 
    // permutation 
    if(s==1){
        //printArr(a, n);
        ans.push_back(a);
        return;
    }
    for(int i = 0; i < s; i++){
        
        if(i!=0){
            //cout<<a[n-1]<<" " <<a[n-s]<<endl;
            if(s%2==0) swap(a[n-i], a[n-s]);
            else swap(a[n-1], a[n-s]);
        }
        heapPermutation(ans, a, s-1, n);
        //(s%2==0)?swap(a[n-i-1], a[n-s]):swap(a[n-1], a[n-s]);
    }
} 

vector<vector<int>> Solution::permute(vector<int> &A) {
    vector<vector<int>>  ans;
    //reverse(A.begin(), A.end());
    heapPermutation(ans, A, A.size(), A.size());
    //cout<<ans.size()<<endl;
    /*for(int i = 0; i < ans.size(); i++){
        reverse(ans[i].begin(), ans[i].end());
        //for(int j = 0; j < ans[i].size(); j++) cout<<ans[i][j]<<" ";
        //cout<<endl;
    }*/
    return ans;
}
