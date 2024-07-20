class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<int> row(rowSum.size(),0);
        vector<int> col(colSum.size(),0);

        vector<vector<int>> mat(rowSum.size(),vector<int>(colSum.size(),0));

        for(int i=0;i<rowSum.size();i++){
            for(int j=0;j<colSum.size();j++){
                mat[i][j] = min(rowSum[i]-row[i],colSum[j]-col[j]);
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }
        return mat;
    }
};