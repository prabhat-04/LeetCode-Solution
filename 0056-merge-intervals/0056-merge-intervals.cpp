class Solution {
    static bool myCmp(vector<int>&x,vector<int>&y){
            return x[0]<y[0];
        // return x[1]<y[1];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),myCmp);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int p=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=ans[p][1]){
                ans[p][1]=max(ans[p][1],intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
                p++;
            }
        }
        return ans;
    }
};