class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> sieve(maxi+1,1);
        sieve[1]=0;
        for(int i=2;i<=sqrt(maxi+1);i++){
            if(sieve[i]){
                for(int j=i*i;j<=maxi;j+=i)
                    sieve[j]=0;
            }
        }

        int curr=1;
        int i=0;
        while(i<nums.size()){
            int diff = nums[i]-curr;
            if(diff<0) return false;
            if(sieve[diff]==1 or diff==0){
                i++;
                curr++;
            }
            else
                curr++;
        }
        return true;
    }
};