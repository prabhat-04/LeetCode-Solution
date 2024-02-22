class Solution {
public:
    // bool isValid(vector<bool> &vis,int n,int ind){
        // if(ind==n+1)
        //     return true;
        // for(int i=1;i<=n;i++){
        //     if(!vis[i-1] && (i%ind==0 || ind%i==0)){
        //         vis[i-1]=true;
        //         if(isValid(vis,n,ind+1)) return true;
        //         vis[i-1]=false;
        //     }
        // }
        // return false;
    // }

    int count(int ind,vector<int> &a){
        if(ind>=a.size()) return 1;
        int ans=0;

        for(int i=ind;i<a.size();i++){
            if(a[i]%(ind+1)==0 || (ind+1)%a[i]==0){
                swap(a[i],a[ind]);
                ans+=count(ind+1,a);
                swap(a[i],a[ind]);
            }
        }

        return ans;
    }

    int countArrangement(int n) {
        // vector<bool> vis(n,false);
        // int cnt =0;
        // for(int i=1;i<=n;i++){
        //     vis[i-1]=true;
        //     if((isValid(vis,n,2))) cnt++;
        //     vis[i-1]=false;
        // }
        // return cnt;

        vector<int> a;
        for(int i=1;i<=n;i++)
            a.push_back(i);
        return count(0,a);
    }
};