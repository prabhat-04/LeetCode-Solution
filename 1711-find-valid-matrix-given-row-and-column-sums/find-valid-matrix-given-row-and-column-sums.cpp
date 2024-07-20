class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {

        vector<vector<int>> mat(rowSum.size(),vector<int>(colSum.size(),0));

        int i=0,j=0;
        while(i<rowSum.size() && j<colSum.size()){
            mat[i][j] = min(rowSum[i],colSum[j]);
            rowSum[i]-=mat[i][j];
            colSum[j]-=mat[i][j];
            rowSum[i]==0 ? i++ : j++;
        }
        return mat;
    }
};