class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        unordered_map<int,int> mp;
        for(int x:arr){
            mp[x]++;
        }
        vector<pair<int,int>> p;
        for(auto it:mp){
            p.push_back({it.second,it.first});
        }
        sort(p.begin(),p.end());
        int i;
        for(i=0;i<p.size()&&k>0;i++){
            cout<<p[i].first<<" "<<p[i].second<<endl;
            if(k>0){
                if(k>=p[i].first){
                    k-=p[i].first;
                }
                else{
                    break;
                }
            }
            else
                break;
        }
        return p.size()-i;
    }
};