class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        sort(arr.begin(),arr.end());
        int val=0,ans=0;
        for(auto &it:arr){
            while(!pq.empty() && pq.top().first < it[0]){
               val = max(val,pq.top().second);
               pq.pop(); 
            }
            ans = max(ans,val+it[2]);
            pq.push({it[1],it[2]});
        }
        return ans;
    }
};