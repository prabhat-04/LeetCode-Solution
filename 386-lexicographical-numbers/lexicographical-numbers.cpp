class Solution {
    void dfs(vector<int> &ans,int num,int n){
        if(num>n) return;
        ans.push_back(num);
        for(int i=0;i<=9;i++){
            dfs(ans,num*10+i,n);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            dfs(ans,i,n);
        }
        return ans;
    }
};