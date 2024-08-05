class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> ans;
        for(int i=0;i<arr.size();i++){
            ans[arr[i]]++;
        }
        int c=0;
        // vector<string> s;
        for(int i=0;i<arr.size();i++){
            if(ans[arr[i]]==1){
                c++;
                if(c==k)
                    return arr[i];
            }
        }
        return "";
    }
};