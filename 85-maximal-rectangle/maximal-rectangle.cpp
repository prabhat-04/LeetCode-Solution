class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> left,right;
        vector<int> l(n),r(n);
        for(int i=0;i<n;i++){
            while(!left.empty() && heights[left.top()] >=heights[i]) left.pop();
            if(left.empty()) l[i]=i+1;
            else l[i] = i-left.top();;
            left.push(i);
        }

        for(int i=n-1;i>=0;i--){
            while(!right.empty() && heights[right.top()]>=heights[i]) right.pop();
            if(right.empty()) r[i]= n-i;
            else r[i] = right.top()-i;
            right.push(i);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans,heights[i]*(r[i]+l[i]-1));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(),m=matrix[0].size();
        vector<vector<int>> mat(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0)
                    mat[i][j] = matrix[i][j]-'0';
                else{
                    if(matrix[i][j]=='1')
                        mat[i][j] = mat[i-1][j] +1;
                }
            }
        }

        int ans = INT_MIN;
        for(auto vec:mat){
            ans = max(ans,largestRectangleArea(vec));
        }
        return ans;
    }
};