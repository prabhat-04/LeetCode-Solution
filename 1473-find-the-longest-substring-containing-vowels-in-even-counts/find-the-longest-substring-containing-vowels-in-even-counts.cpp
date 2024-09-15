class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int>prefix(s.size());
        int ans = 0;
        unordered_map<int,int> mp;
        int bit =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                bit^=(1<<4);
            }
            else if(s[i]=='e')
                bit^=(1<<3);
            else if(s[i]=='i')
                bit^=(1<<2);
            else if(s[i]=='o')
                bit^=(1<<1);
            else if(s[i]=='u')
                bit^=1;
            prefix[i]=bit; 
            if(mp.find(prefix[i])!=mp.end()){
                ans = max(ans,i-mp[prefix[i]]);
            }
            else{
                mp[prefix[i]]=i;
            }
            if(prefix[i]==0){
                ans=max(ans,i+1);
            }      
        }
        return ans;
    }
};