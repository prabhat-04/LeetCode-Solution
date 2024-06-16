class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int reach = 0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(reach>=n) return ans;
            if(reach<nums[i]-1){
                reach+=(reach+1);
                ans++;
                i--;
            }
            else
                reach+=nums[i];
        }
        // if(reach>=n)
           
        while(reach<n){
            reach+=(reach+1);
            ans++;
        }
        // cout<<reach<<endl;
        return ans;
    }
};