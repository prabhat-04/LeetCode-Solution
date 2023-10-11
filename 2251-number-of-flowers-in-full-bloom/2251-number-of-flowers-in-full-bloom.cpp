class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans;
        vector<int> left,right;
        for(int i=0;i<flowers.size();i++){
            left.push_back(flowers[i][0]);
            right.push_back(flowers[i][1]);
        }
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());

        for(int i=0;i<people.size();i++){
            int j = upper_bound(left.begin(),left.end(),people[i]) - left.begin();
            int k = lower_bound(right.begin(),right.end(),people[i]) - right.begin();
            ans.push_back(j-k);
        }
        return ans;
    }
};