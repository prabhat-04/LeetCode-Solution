class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int left =0;
        int right = position[position.size()-1]-position[0];
        int ans = -1;
        while(left<=right){
            int mid = left + (right-left)/2;
            int countOfBalls=1;
            int prevPosition = position[0];
            for(int i=1;i<position.size();i++){
                if(  position[i] >= (prevPosition+ mid)  ){
                    countOfBalls++;
                    prevPosition = position[i];
                }
            }
            if(countOfBalls >= m){
                ans =  mid;
                left = mid+1;
            }
            else
                right = mid-1;
            // cout<<countOfBalls<<endl;
            // cout<<left<<" "<<right<<endl;
        }
        return ans;
    }
};