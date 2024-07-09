class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        double ans =0;
        int time = customers[0][0];
        for(auto it:customers){
            if(time>=it[0])
                time+=it[1];
            else
                time=it[0]+it[1];
            ans+=(time-it[0]);
        }
        return ans/customers.size();
    }
};