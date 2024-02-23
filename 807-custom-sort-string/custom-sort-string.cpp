class Solution {
public:

    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<order.size();i++)
            mp[order[i]]=i;

        sort(s.begin(),s.end(),[&](char &a,char &b){
            if(mp.find(a)!=mp.end() && mp.find(b)!=mp.end())
                return mp[a] < mp[b];
            if(mp.find(a)==mp.end())
                return false;
            else return true;
        });
        return s;
    }
};