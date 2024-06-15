class Solution {
    struct ComparePairs {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    }
};
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> pq;
        vector<pair<int,int>> vec;
        for(int i=0;i<profits.size();i++){
            vec.push_back({capital[i],profits[i]});
        }
        sort(vec.begin(),vec.end());
        int j=0;
        for(int i=0;i<k;i++){
            while(j<vec.size() && vec[j].first<=w){
                pq.push(vec[j]);
                j++;
            }
            if(!pq.empty()){
                w+=pq.top().second;
                pq.pop();
            }
        }
        return w;
    }
};