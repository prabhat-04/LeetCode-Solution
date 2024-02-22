class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 && n==1) return 1;
        pair<int,int> p={-1,INT_MIN};
        unordered_map<int,int> mp1,mp2;
        for(auto it:trust){
            mp1[it[0]]++;
            mp2[it[1]]++;
            if(p.second < mp2[it[1]]){
                p.first = it[1];
                p.second = mp2[it[1]];
            }
        }

        return mp2[p.first]==n-1 && mp1[p.first]==0 ?p.first:-1;
    }
};