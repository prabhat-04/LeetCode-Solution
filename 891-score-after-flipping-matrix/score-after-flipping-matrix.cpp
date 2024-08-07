#pragma GCC optimize("O3", "unroll-loops")
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        int score = (1 << (m - 1)) * n;
        for(int j = 1; j < m; ++j) {
            int val = 1 << (m - 1 - j);
            int set = 0;

            for(int i = 0; i < n; ++i) {
                if(grid[i][j] == grid[i][0]) {
                    set++;
                }
            }

            score += max(set, n - set) * val;
        }
        
        return score;
    }
};