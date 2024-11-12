class Solution {
    int binarySearch(vector<vector<int>> &items,int target){
        int low=0,high=items.size()-1;
        int ans=0;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(items[mid][0]>target)
                high=mid-1;
            else{
                ans = max(ans,items[mid][1]);
                low=mid+1;
            }
        }
        return ans;
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end(),[](vector<int> &a,vector<int> &b){
            return a[0] < b[0];
        });
        for(int i=1;i<items.size();i++){
            items[i][1] =  max(items[i][1],items[i-1][1]);
        }
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            ans[i] = binarySearch(items,queries[i]);
        }
        return ans;
    }
};