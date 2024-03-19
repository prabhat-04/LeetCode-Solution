class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        int maxfreq=INT_MIN,cnt=1;
        for(char ch:tasks){
            mp[ch]++;
            if(mp[ch]>maxfreq){
                maxfreq=mp[ch];
                cnt=1;
            }
            else if(mp[ch]==maxfreq){
                cnt++;
            }
        }
        // cout<<maxfreq<<" "<<cnt<<endl;
        int temp = (n+1) * (maxfreq-1) + cnt;
        if(tasks.size()>temp) return tasks.size();
        return temp;
        // return max(tasks.size(),temp);
    }
};