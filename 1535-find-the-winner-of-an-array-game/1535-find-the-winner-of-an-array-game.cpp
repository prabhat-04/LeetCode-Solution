class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k==1)
            return max(arr[0],arr[1]);
        if(k>=arr.size()){
           return *max_element(arr.begin(),arr.end());
        }
        int curr=arr[0],wins=0;
        for(int i=1;i<arr.size();i++){
            if(curr>arr[i])
                wins++;
            else{
                curr=arr[i];
                wins=1;
            }
            if(wins==k)
                return curr;
        }
        return curr;
    }
};