class Solution {
public:
    int getLucky(string s, int k) {
        string str = "";
        for(char c:s){
            str += to_string(c-'a'+1);
        }
        cout<<str<<endl;
        int ans;
        for(int i=0;i<k;i++){
            ans = 0;
            for(char c:str){
                ans += (c-'0');
            }
            str = to_string(ans);
        }
        return ans;
    }
};