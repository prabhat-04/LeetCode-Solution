class Solution {
public:
    int maxDepth(string s) {
        int op=0;
        // int cl=0;
        int max = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                op++;
            else if(s[i]==')'){
                if(max<op){
                    max=op;
                }
                op--;
            }  
        }
        return max;
    }
};