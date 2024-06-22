class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int niceSubarray=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1)
                nums[i]=1;
            else
                nums[i]=0;
            if(i>0)
                nums[i]+=nums[i-1];
            if(nums[i]==k)
                niceSubarray++;
            if(mp.find(nums[i]-k)!=mp.end()){
                niceSubarray+=mp[nums[i]-k];
            }
            mp[nums[i]]++;
        }
        return niceSubarray;
        
    }
};