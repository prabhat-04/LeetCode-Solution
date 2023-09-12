class Solution {
public:
    int minDeletions(string s) {
        unordered_map <char,int> mp;
        for(auto x : s)
            mp[x]++;
        vector<int> vec;
        for(auto x: mp)
            vec.push_back(x.second);
        sort(vec.begin(), vec.end(), greater<int>());
        int ans = 0;
        for(int i=1;i<vec.size();i++){
            if(vec[i-1]==0){
                ans += vec[i];
                vec[i]=0;
            }
            else if(vec[i-1] <= vec[i]){
                ans += vec[i] - (vec[i-1]-1);
                vec[i] = vec[i-1] - 1;
            }
        }
        return ans;
    }
};