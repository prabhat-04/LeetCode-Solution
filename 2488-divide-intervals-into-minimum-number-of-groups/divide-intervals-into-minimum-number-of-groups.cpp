class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int start = INT_MAX;
        int end = INT_MIN;
        for(auto it:intervals){
            start = min(start,it[0]);
            end = max(end,it[1]);
        }
        vector<int> vec(end+2,0);
        for(auto it:intervals){
            vec[it[0]]++;
            vec[it[1]+1]--;
        }
        int ans =0,curr=0;
        for(int i=start;i<=end;i++){
            curr += vec[i];
            ans = max(ans,curr);
        }
        return ans;
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();