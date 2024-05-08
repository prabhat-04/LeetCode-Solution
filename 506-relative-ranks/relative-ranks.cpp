class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // int n = score.size()-1;
        vector<pair<int,int>> vec;
        for(int i=0;i<score.size();i++){
            vec.push_back({score[i],i});
        }
        sort(vec.rbegin(), vec.rend());
        vector<string> ans(score.size());
        for(int i=0;i<vec.size();i++){
            int s= vec[i].first;
            int ind = vec[i].second;
            if(i==0){
                ans[ind]="Gold Medal";
            }
            else if(i==1){
                ans[ind]="Silver Medal";
            }
            else if(i==2){
                ans[ind]="Bronze Medal";
            }
            else{
                ans[ind]=to_string(i+1);
            }
            cout<<i<<endl;
        }
        return ans;
    }
};