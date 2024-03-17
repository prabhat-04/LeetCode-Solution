class Solution {
struct TrieNode{
    TrieNode *child[26];
    bool isEnd = false;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};
TrieNode* root = new TrieNode();

void insert(string word) {
    TrieNode *ptr = root;
    for(char ch:word ){
        if(!ptr->child[ch-'a']){
            ptr->child[ch-'a'] = new TrieNode();
        }
        ptr = ptr ->child[ch-'a'];
    }
    ptr->isEnd = true;
}

int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void dfs(vector<vector<char>> &board,int i,int j,TrieNode *ptr,string temp,vector<string> &ans,vector<vector<bool>> &vis){
    if(ptr->isEnd){
        ans.push_back(temp);
        ptr->isEnd=false;
    }
    if(!ptr || !ptr->child[board[i][j]-'a']) return;
    int n = board.size() , m = board[0].size();
    vis[i][j] = true;
    for(int k=0;k<4;k++){
        int new_i = i+dir[k][0];
        int new_j = j+dir[k][1];
        if(new_i<n && new_i>=0 && new_j<m && new_j>=0 && !vis[new_i][new_j])
            dfs(board,new_i,new_j,ptr->child[board[i][j]-'a'],temp+board[i][j],ans,vis);
    }
    if(ptr->child[board[i][j]-'a']->isEnd){
        ans.push_back(temp+board[i][j]);
        ptr->child[board[i][j]-'a']->isEnd=false;
    }
    
    vis[i][j]=false;
}

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto s : words){
            insert(s);
        }
        vector<string> ans;
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                dfs(board,i,j,root,"",ans,vis);
            }
        }
        return ans;
    }
};