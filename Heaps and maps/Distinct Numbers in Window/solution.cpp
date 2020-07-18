vector<int> Solution::dNums(vector<int> &A, int B) { 
    int n = A.size();
    if(B>n) return {};
    map<int,vector<int>> m;
    for(int i = 0; i < n; i++){
        m[A[i]].push_back(i);
    }
    
    vector<int> ans;
    int cnt = 0;
    map<int, int> repe;
    for(int i = 0; i < B; i++){
        if(repe.find(A[i])==repe.end()){
        if(m[A[i]].size()>1){
            //repe.push_back(A[i]);
            int precnt = cnt;
            for(int j = 1; j < m[A[i]].size(); j++){
                if(m[A[i]][j]<B) cnt++;
                else if(m[A[i]][j]>=B) break;
            }
            repe[A[i]] = cnt-precnt;
        }
        else repe[A[i]] = 0;
        }
    }
    ans.push_back(B-cnt);
    for(int i = 1; i<n-B+1; i++){
        //if(find(A.begin()+i, A.begin()+B-1+i, A[i-1])!=A.begin()+B+i-1) cnt--;
        //else cnt--;
        //if(find(A.begin()+i, A.begin()+B-1+i, A[B+i-1])!=A.begin()+B+i-1) cnt++;
        //else cnt--;
        //cout<<cnt<<endl;
        //cout<<repe[A[i-1]]<<" "<<A[i-1]<<endl;
        if(repe[A[i-1]]>0){ 
            cnt--;
            repe[A[i-1]]--;
        }
        else{
            repe.erase(A[i-1]);
        }
        if(repe.find(A[B+i-1])==repe.end()) repe[A[B+i-1]] = 0;
        else{ 
            cnt++;
            repe[A[B+i-1]]++;
        }
        //cout<<cnt<<endl;
        ans.push_back(B-cnt);
    }
    return ans;
}
