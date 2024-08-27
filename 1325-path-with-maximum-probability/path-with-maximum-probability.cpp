class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>> graph;
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        vector<double> maxProb(n,0);
        maxProb[start]=double(1);
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(curr.second==end)
                return curr.first;
            for(auto it: graph[curr.second]){
                if(curr.first * it.second > maxProb[it.first]){
                    maxProb[it.first] = curr.first * it.second;
                    pq.push({maxProb[it.first],it.first});
                }
            }
        }
        return 0;
    }
};