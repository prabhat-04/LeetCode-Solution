class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int step[3]={};
        for(int i=1;i<cost.size();i++){
            step[0]=step[1];
            step[1]=step[2];
            step[2]=min(cost[i]+step[1],cost[i-1]+step[0]);
        }
        return step[2];
    }
};