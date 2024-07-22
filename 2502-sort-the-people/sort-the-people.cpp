class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> vec(n);
        iota(vec.begin(),vec.end(),0);

        sort(vec.begin(),vec.end(),[&heights](int a,int b){
            return heights[a] > heights[b];
        });

        vector<string> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=(names[vec[i]]);
        }
        return ans;
    }
};