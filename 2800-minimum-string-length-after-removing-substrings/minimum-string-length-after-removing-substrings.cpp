class Solution {
public:
    int minLength(string s) {
        while(s.size()>0){
            string ans = "";
            int cnt=0;
            for(int i=0;i<s.size();i++){
                if(i<s.size()-1 && s[i]=='A' && s[i+1]=='B'){
                    i++;
                    cnt++;
                }
                else if( i<s.size()-1 && s[i]=='C' && s[i+1]=='D'){
                    i++;
                    cnt++;
                }
                else
                    ans+=s[i];
            }
            s = ans;
            if(cnt ==0 )break;
        }
        return s.size();
    }
};