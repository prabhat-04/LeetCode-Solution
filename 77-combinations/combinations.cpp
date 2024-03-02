class Solution {
public:
    void help(int i,int n,int k,vector<vector<int>> &ans,vector<int> &temp){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<=n;j++){
            temp.push_back(j);
            help(j+1,n,k,ans,temp);
            temp.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        help(1,n,k,ans,temp);
        return ans;
    }
};