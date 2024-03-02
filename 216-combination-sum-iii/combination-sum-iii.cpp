class Solution {
public:
    void help(int i,int n,int k,vector<vector<int>> &ans,int &temp,vector<int> &vec){
        if(temp>n || vec.size()>k) return;
        if(temp==n && vec.size()==k){
            ans.push_back(vec);
            return;
        }
        for(int j=i;j<=9;j++){
            temp+=j;

            vec.push_back(j);
            help(j+1,n,k,ans,temp,vec);
            vec.pop_back();
            temp-=j;
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        int temp=0;
        vector<int> vec;
        help(1,n,k,ans,temp,vec);
        return ans;
    }
};