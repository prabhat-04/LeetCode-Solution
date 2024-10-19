int speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    char findKthBit(int n, int k) {
        if(k==1) return '0';
        if(k==2 || k==3 || k==4) return '1'; 
        vector<int>vec(k);
        vec[0]=0;
        vec[1]=1;
        vec[2]=1;
        vec[3]=1;
        for(int i=4;i<k;i++){
            int j=i-2;
            while(j>=0){
                vec[i] = !vec[j];
                if(i==k-1) return vec[k-1]+'0';
                j--;
                i++;
            }
            vec[i]=1;
        }
        return vec[k-1]+'0';
    }
};