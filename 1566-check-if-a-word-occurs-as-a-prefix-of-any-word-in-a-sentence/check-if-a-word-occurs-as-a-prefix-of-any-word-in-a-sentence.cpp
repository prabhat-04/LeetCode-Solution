class Solution {
public:
    int isPrefixOfWord(string sen, string sear) {
        int i=0,j=0;
        int cnt=1;
        while(i<sen.size()){
            if(sen[i]==sear[j]){
                i++;
                j++;
                if(j==sear.size()) return cnt;
            }
            else{
                while(i<sen.size() && sen[i]!=' ')
                    i++;
                i++;
                cnt++;
                j=0;
            }
        }
        return -1;
    }
};