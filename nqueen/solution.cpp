void che(vector<string> res, int A){
    for(int i = 0; i < A; i++){
        for(int j = 0; j < A; j++) cout<<res[i][j]<<" ";
        cout<<endl;
    }
}
bool call(vector<vector<string>> &res,vector<string> &x, int A, vector<string> temp, int ini){
    //if conditions satisfies then mark as true
    if(ini==A){
        return 1;
    }
    //to check every condition
    for(int i = 0; i < A; i++){
        // check the effect of the queen
        if(x[ini][i] != '.'){
        //convert every location to '.' for the present location of queen
        for(int j = 0; j < A; j++){
            x[ini][j] = '.';
            x[j][i] = '.';
            if(i+j < A && ini+j < A) x[ini+j][i+j] = '.';
            if(i-j >= 0 && ini+j<A) x[ini+j][i-j] = '.';
        }
            // present location of the queen
            x[ini][i] = 'Q';
            //che(x, A);
            //cout<< i << ini << endl;
            
            //use backtracking to check whether any of the combination satisfies the condition  
            if(call(res, x,A, x, ini+1)){ 
                //return 1;
                res.push_back(x);
            }
            //if(ini==0)
            x = temp;//convert to initial matrix for every row so that check another combination
        }
        
        
    }
    //for returning to main 
    if(ini==0) return 1;
    //
    return 0;
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string>> res;
    vector<string> x, temp;
    string s;
    for(int j = 0; j < A; j++){
        s+='-';
            //x.push_back("-");
    }
    for(int j = 0; j < A; j++){
        //s+='-';
        x.push_back(s);
        temp.push_back(s);
    }
    /*for(int i = 0; i < A; i++){
        res.push_back(x);
        temp.push_back(x);
    }*/
    if(call(res, x,A, temp, 0))
    return res;
    vector<vector<string>> k;
    //cout<<5<<endl;
    return k;
    
    
}
