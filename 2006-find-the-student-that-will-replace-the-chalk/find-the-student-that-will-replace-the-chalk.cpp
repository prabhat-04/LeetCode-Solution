class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum=0;
        for(int i=0;i<chalk.size();i++){
            if(k>=chalk[i]){
                k-=chalk[i];
                sum+=chalk[i];
            }
            else
                return i;
        }
        // cout<<sum<<endl;
        k = k%sum;
        // cout<<k<<endl;
        for(int i=0;i<chalk.size();i++){
            if(k>=chalk[i]){
                k-=chalk[i];
                sum+=chalk[i];
            }
            else
                return i;
        }
        return -1;
    }
};