class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(i>0 && curr%k==0) return true;
            
            if(mp.find(curr%k)!=mp.end()){
                if(i-mp[curr%k]>1)
                return true;
            }
            else
                mp[curr%k]=i;
        }
        return false;
    }
};