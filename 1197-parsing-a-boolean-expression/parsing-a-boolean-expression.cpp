class Solution {
    bool helper(string& exp,int& ind){
        char curr = exp[ind++];
        if(curr=='t') return true;
        if(curr =='f') return false;
        if(curr=='!'){
            ind++;
            bool res = !helper(exp,ind);
            ind++;
            return res;
        }
        vector<bool> val;
        ind++;
        while(exp[ind]!=')'){
            if(exp[ind]!=','){
                val.push_back(helper(exp,ind));
            }
            else
                ind++;
        }
        ind++;
        if(curr=='&'){
            for(bool b :val){
                if(!b) return false;
            }
            return true;
        }
        if(curr=='|'){
            for(bool v:val){
                if(v) return true;
            }
            return false;
        }
        return false;
        
    }
public:
    bool parseBoolExpr(string expression) {
        int ind =0;
        return helper(expression,ind);
    }
};