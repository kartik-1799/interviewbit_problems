const int ALPHABET_SIZE = 26; 
vector<string> split(string A, char delimeter){
    A+=delimeter;
    vector<string> v;
    int i = 0;
    while(i < A.size()){
        string s;
       // cout<<A[i]<<endl;
        while(A[i]!=delimeter){
            s+=A[i];
            i++;
        }
        //cout<<s<<endl;
        v.push_back(s);
        i++;
    }
    //cout<<v.size()<<endl;
    return v;
}
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
  
// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
vector<int> Solution::solve(string A, vector<string> &B) {
    vector<string> s = split(A, '_');
    TrieNode* node = getNode();
    //cout<<s.size()<<endl;
    for(auto i : s) insert(node,i);
    //cout<<1<<endl;
    map<int, queue<int>, greater<int>> m;
    for(int i = 0; i < B.size(); i++){
        int cnt = 0;
        string k = B[i];
        vector<string> temp = split(k, '_');
        for(auto i : temp){
            if(search(node, i)) cnt++;
        }
        m[cnt].push(i);
    }
    //sort(m.begin(), m.end());
    vector<int> res;
    for(auto i = m.begin(); i != m.end(); ++i){
        queue<int> que = i->second;
        while(!que.empty()){
            res.push_back(que.front());
            que.pop();
        }
    }
    return res;
    
}
