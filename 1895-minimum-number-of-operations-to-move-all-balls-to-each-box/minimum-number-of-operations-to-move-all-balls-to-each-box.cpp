class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>left(n),right(n);
        int sum=0,cnt=0;
        for(int i=n-1;i>=0;i--){
            sum+=cnt;
            right[i]=sum;
            if(boxes[i]=='1') cnt++;
        }
        sum=0;
        cnt=0;
        for(int i=0;i<n;i++){
            sum+=cnt;
            left[i]=sum;
            if(boxes[i]=='1') cnt++;
            left[i]+=right[i];
        }
        return left;
    }
};