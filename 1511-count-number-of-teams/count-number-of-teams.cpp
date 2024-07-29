class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams =  0;
        for(int i=0;i<n;i++){
            int l=0,r=0;
            for(int j=i-1;j>=0;j--){
                if(rating[j] <rating [i])
                    l++;
            }
            for(int j=i+1;j<n;j++){
                if(rating[i]<rating[j])
                    r++;
            }

            teams+= l*r;
            int p = i - l;
            int q = n - i - 1 - r;

            teams += p*q;
    
        }
        return teams;
    }
};