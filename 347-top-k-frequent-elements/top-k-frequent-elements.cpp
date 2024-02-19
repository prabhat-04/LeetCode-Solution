class Solution {
public:
    struct comp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second < b.second;
    }
};
 

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x:nums)
            mp[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        for(auto it:mp)
            pq.push(it);
        vector<int> ans;
        while(k>0){
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return ans;
    }
};