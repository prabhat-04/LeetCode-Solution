class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> vec;
        for(int i=0;i<difficulty.size();i++){
            vec.push_back({difficulty[i],profit[i]});
        }
        sort(vec.begin(),vec.end());
        sort(worker.begin(),worker.end());
        int max_profit = 0, best = 0, i = 0;
        
        for(int ability : worker) {
            while(i < vec.size() && vec[i].first <= ability) {
                best = max(best, vec[i].second);
                ++i;
            }
            max_profit += best;
        }
        
        return max_profit;
    }
};