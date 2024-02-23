class Solution {
public:
    
    static bool comp(const pair<char,int> &a,const pair<char,int> &b){
        return a.second<b.second;
    }

    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<order.size();i++)
            mp[order[i]]=i;
        vector<pair<char,int>> vec;
        int k= mp.size();
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end())
                vec.push_back({s[i],mp[s[i]]});
            else{
                vec.push_back({s[i],k});
                k++;
            }
        }
        sort(vec.begin(),vec.end(),comp);
        s="";
        for(auto x:vec)
            s+=x.first;
        return s;
    }
};