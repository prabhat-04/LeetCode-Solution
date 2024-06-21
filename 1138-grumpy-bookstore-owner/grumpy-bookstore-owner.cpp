class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        vector<int> vec(grumpy.size());
        int maxCustomer = 0;
        for(int i=0;i<grumpy.size();i++){
            vec[i] = grumpy[i] * customers[i];
            if(grumpy[i]==0){
                maxCustomer+=customers[i];
            }
        }
        for(int i=1;i<vec.size();i++){
            vec[i]+=vec[i-1];
        }
        int ans = vec[minutes-1];
        for(int i=minutes;i<vec.size();i++){
            ans = max(ans,vec[i]-vec[i-minutes]);
        }
        return maxCustomer + ans;
    }
};