class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        for(int i=0;i<arr.size();i++){
            arr[i] = ((arr[i]%k)+k)%k;
        }
        sort(arr.begin(),arr.end());
        int cnt=0;
        int i=0;
        while(i<arr.size() && arr[i]==0){
            cnt++;
            i++;
        }
        if(cnt%2!=0)    return false;
        int j=arr.size()-1;
        while(i<j){
            if(arr[i]+arr[j]!=k) return false;
            i++;
            j--;
        }
        return true;
    }
};