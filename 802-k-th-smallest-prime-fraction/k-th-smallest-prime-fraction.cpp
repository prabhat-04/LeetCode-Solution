class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i=0;i<arr.size();i++){
            pq.push({-1.0 * arr[i]/arr.back(),{i,arr.size()-1}});

        }
        while(--k>0){
            auto curr = pq.top().second;
            pq.pop();
            curr.second--;
            pq.push({-1.0 * arr[curr.first]/arr[curr.second],{curr.first,curr.second}});
        }
        auto ans = pq.top().second;
        return {arr[ans.first],arr[ans.second]};
    }
};