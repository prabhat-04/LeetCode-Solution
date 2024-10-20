class Solution {
    char helper(char op,vector<char> &val){
        if(op =='!') return val[0]=='t'?'f':'t';
        if(op == '&'){
            for(char v:val){
                if(v=='f') return 'f';
            }
            return 't';
        }
        if(op =='|'){
            for(char v:val){
                if(v=='t') return 't';
            }
            return 'f';
        }
        return 'f';
    }
public:
    bool parseBoolExpr(string exp) {
        stack<char> st;
        for(char c:exp){
            if(c==')'){
                vector<char> val;
                while(st.top()!='('){
                    val.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                char res = helper(op,val);
                st.push(res);
            }
            else if(c!=',')
                st.push(c);
        }
        return st.top()=='t';
    }
};