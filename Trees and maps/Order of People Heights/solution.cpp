vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    map<int , int, greater<int>> m;
    for(int i = 0; i < A.size(); i++){
        m[A[i]] = B[i];
    }
    vector<int> v;
    for(auto& it : m ){
        v.insert(v.begin()+it.second, it.first);
    }
    return v;
    /*for(auto it = m.begin(); it!=m.end(); ++it){
        if(it->second.size()>1) sort(it->second.begin(), it->second.end());
    }
    
    int temp = 0;
    int i = 0;
    int n = A.size();
    
    while(i<n){
        if(m[temp].size()==0){
               temp++;
               if(temp==m.size()) temp = 0;
            //    i--;
            continue;
        }
        cout<<m[temp].size()<<" "<<temp<<endl;
        if(temp<m.size()-1){
            A[i] = *m[temp].begin();
            int k = 1;
            while(temp+k < m.size() && m[temp+k].size()==0) k++;
            if(temp+k==m.size()){
                m[temp].erase(m[temp].begin());
                temp=0;
                i++;
                continue;
            }
            if(*m[temp].begin() > *m[temp+k].begin()) temp++;
            m[temp].erase(m[temp].begin());
            i++;
            
        }
        else{
            A[i] = *m[temp].begin();
            m[temp].erase(m[temp].begin());
            i++;
            temp = 0;
        }
        
    }
    return A;
    /*for(int i = 0; i < A.size(); i++){
        if(B[i]==i &&(i] A[i] < A[m])){
            if(i==0){
                m = i;
            }
            else{
                if(A[i]<A[m]){
                    m = i;
                }
            }
        }
        else if(B[i]>i){
            //int diff = B[i]-i;
            
                for(int j  = i+1;  j < n; j++){
                    if(B[j]==i && A[j] < A[m]){
                        m = i;
                        swap(B[j],B[i]);
                        swap(A[j], A[i]);
                        break;
                    }
                    else if(B[j]<i){
                        int cnt = 0;
                        for(int k = 0; k < i; k++){
                            if(A[k] > A[j]) cnt++;
                        }
                        if(cnt==B[j]){
                            swap(B[j], B[i]);
                            swap(A[j], A[i]);
                            break;
                        }
                    }
                }
            
        }
    }*/
}
