class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = INT_MAX,h=INT_MIN;
        for(auto it:bloomDay){
            l = min(l,it);
            h = max(h,it);
        }
        int minDays = INT_MAX;
        while(l<=h){
            int mid = l + (h-l)/2;
            int cnt=0,ans=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    cnt++;
                }
                else
                    cnt=0;
                if(cnt>=k){
                    ans++;
                    cnt=0;
                }
            }
            if(ans>=m){
                minDays = mid;
                h=mid-1;
            }
            else
                l=mid+1;
            // cout<<l<<" "<<h<<endl;

        }
        return minDays==INT_MAX?-1:minDays;
    }
};