class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        if(original.size()!=(m*n)) return {};
        if(m==1)
            return {original};
        int i=0,j=0;
        vector<vector<int>> ans(m,vector<int>(n));
        for(int k=0;k<original.size();k++){
            ans[i][j]=original[k];
            j++;
            if(j==n){
                j=0;
                i++;
            }
        }
        return ans;
    }
};