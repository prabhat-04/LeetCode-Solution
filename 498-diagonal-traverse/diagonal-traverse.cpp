class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(),n=mat[0].size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        int i=0;
        vector<int> ans;
        while(i<mp.size()){
            if(i%2==0)
                reverse(mp[i].begin(),mp[i].end());
            for(int x:mp[i]) ans.push_back(x);
            i++;
        }
        return ans;
    }
};