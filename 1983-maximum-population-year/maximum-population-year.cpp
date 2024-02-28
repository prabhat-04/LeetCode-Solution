class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> popu(102,0);
        for(auto x:logs){
            popu[x[0]-1950]++;
            popu[x[1]-1950]--;
        }
        int maxPopu=popu[0], ans = -1;
        for(int i=1;i<102;i++){
            popu[i] = popu[i] + popu[i-1];
            if(maxPopu < popu[i]){
                maxPopu=popu[i];
                ans= i;
            }
        }
        return ans+1950==1949?1950:ans+1950;
    }
};