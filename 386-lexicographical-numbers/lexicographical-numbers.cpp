class Solution {
    void dfs(vector<int> &ans,int num,int n){
        if(num>n) return;
        ans.push_back(num);
        for(int i=0;i<=9;i++){
            int next = num*10+i;
            if(next<=n)
                dfs(ans,next,n);
            else
                break;
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