class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xor1=0;
        for(auto &it:derived) xor1^=it;
        return xor1==0;
    }
};