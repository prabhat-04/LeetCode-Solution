class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ans = heights;
        int count=0;
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=heights[i])
                count++;
        }
        return count;
    }
};