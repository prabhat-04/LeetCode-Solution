class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans =0;
        int time = customers[0][0];
        for(auto it:customers){
            if(time>=it[0])
                time+=it[1];
            else
                time=it[0]+it[1];
            ans+=(time-it[0]);
            
            cout<<ans<<" "<<time<<endl;
        }
        return ans/customers.size();
    }
};