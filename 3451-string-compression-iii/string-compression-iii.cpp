class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int i=0;
        while(i<word.size()){
            char c = word[i];
            int cnt =0;
            while(cnt<9 && i<word.size() && word[i]==c){
                cnt++;
                i++;
            }
            char ch = (cnt+'0');
            ans+=ch;
            ans+=c;
            // ans+=((cnt+'0')+c);
        }
        return ans;
    }
};