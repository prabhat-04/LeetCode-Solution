class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        int zero=0;
        for(int it:arr){
            if(st.find(2*it)!=st.end() && it!=0) return true;
            if(it%2==0 && st.find(it/2)!=st.end() && it!=0) return true;
            if(it==0) zero++;
            st.insert(it);
        }
        if(zero) return zero>=2;
        return false;
    }
};