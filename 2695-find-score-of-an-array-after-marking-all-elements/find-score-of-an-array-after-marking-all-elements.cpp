class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        vector<bool> mark(nums.size(),false);
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(mark[curr.second]) continue;
            ans += curr.first;
            mark[curr.second]=true;
            if(curr.second>0) mark[curr.second-1]=true;
            if(curr.second<mark.size()-1) mark[curr.second+1]=true;
        }
        return ans;
    }
};