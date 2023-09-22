class Solution {
public:
    bool isSubsequence(string s, string t){ 
        if(s=="" && t=="")
            return true;
        int i=0,j=0;
        while(i<t.size()){
            if(t[i]==s[j])
                j++;
            if(j==s.size())
                return true;
            i++;
        }
        return false;
    }
};