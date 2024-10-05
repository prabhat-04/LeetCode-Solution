class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size(),n = s2.size();
        unordered_map<char,int> mp;
        for(char c: s1) mp[c]++;
        int c = mp.size();
        int i=0,j=0;
        while(j<n){
            if(mp.find(s2[j])!=mp.end()){
                mp[s2[j]]--;
                if(mp[s2[j]]==0) c--;
            }
            if((j-i+1)<k) j++;
            else if((j-i+1)==k){
                if(c==0) return true;
                if(mp.find(s2[i])!=mp.end()){
                    mp[s2[i]]++;
                    if(mp[s2[i]]==1) c++;
                }
                i++;
                j++;
            }
        }
        return false;
    }
};