class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(), m=s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j=0, satisfied=0;
        for (int i=0; i<n && j<m; i++){
            j=lower_bound(s.begin()+j, s.end(), g[i])-s.begin();
        //    cout<<"j="<<j<<","<<g[i]<<endl;
            if (j<m) {
                j++;
                satisfied++;
            }
        } 
        return satisfied;
    }
};