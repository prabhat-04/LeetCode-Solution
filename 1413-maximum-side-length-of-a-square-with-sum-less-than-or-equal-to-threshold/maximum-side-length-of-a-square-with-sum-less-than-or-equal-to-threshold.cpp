class Solution {
public:
    bool isPossible(vector<vector<int>>& mat,int mid, int threshold){
        int n=mat.size()-1,m=mat[0].size()-1;
        for(int i=mid;i<=n;i++){
            for(int j=mid;j<=m;j++){
                if(mat[i][j]-mat[i-mid][j]-mat[i][j-mid]+mat[i-mid][j-mid]<=threshold)
                    return true;
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(),m=mat[0].size();
        vector<vector<int>> prefix(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }

        int low=0,high=min(n,m);
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(prefix,mid,threshold))
                low=mid+1;
            else
                high=mid-1;
        }
        return high;
    }
};