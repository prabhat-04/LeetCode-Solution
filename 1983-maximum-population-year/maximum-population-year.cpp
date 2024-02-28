class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> popu(101,0);
        for(auto x:logs){
            popu[x[0]-1950]++;
            popu[x[1]-1950]--;
        }
        int maxPopu=popu[0], ans = 0;
        for(int i=1;i<101;i++){
            popu[i] = popu[i] + popu[i-1];
            if(maxPopu < popu[i]){
                maxPopu=popu[i];
                ans= i;
            }
        }
        return ans+1950;
    }
};