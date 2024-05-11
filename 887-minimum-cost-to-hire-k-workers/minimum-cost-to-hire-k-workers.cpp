class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double ans = numeric_limits<double>::max();
        double curr = 0;
        vector<pair<double,int>> vec;
        for(int i=0;i<n;i++){
            vec.emplace_back(static_cast<double>(wage[i])/quality[i],quality[i]);
            
        }
        ranges::sort(vec);
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(vec[i].second);
            curr+=vec[i].second;

            if(pq.size()>k){
                curr-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans = min(ans,curr * vec[i].first);
            }
        }
        return ans;
    }
};