class Solution {
    bool isPossible(vector<int> &piles,int k,int h){
        double sum=0;
        for(auto it:piles){
            sum+= ceil((double)it/k);
        }
        if(sum>h) return false;
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high = *max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(piles,mid,h)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};