class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> vec(n,false);
        for(auto &it:edges){
            vec[it[1]]=true;
        }
        int ans=-1;
        for(int i=0;i<vec.size();i++){
            if(!vec[i] && ans==-1){
                ans=i;
            }
            else if(!vec[i]){
                return -1;
            }
        }
        return ans;
    }
};