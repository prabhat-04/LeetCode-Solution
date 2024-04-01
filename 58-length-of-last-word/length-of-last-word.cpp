class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        bool flag = false;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '){
                if(!flag) continue;
                else break;
            }
            else
                flag=true;
            cnt++;
        }
        return cnt;
    }
};