class Solution {
    static const int HASH_MULTIPLIER = 60001;

    int hash(int x,int y){
        return x + HASH_MULTIPLIER * y;
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> st;
        for(auto & it:obstacles){
            st.insert(hash(it[0],it[1]));
        }

        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        vector<int> curr = {0,0};
        int ans = 0;
        int currDir = 0;
        for(int it: commands){
            if(it==-1){
                currDir = (currDir+1)%4;
                continue;
            }
            if(it==-2){
                currDir = (currDir+3)%4;
                continue;
            }
            vector<int> dire = dir[currDir];
            for(int step=0;step<it;step++){
                int x = curr[0] +dire[0];
                int y = curr[1] + dire[1];
                if(st.contains(hash(x,y)))
                    break;
                curr[0] = x;
                curr[1] = y;
            }
            ans = max(ans,curr[0]*curr[0] + curr[1]*curr[1]);

        }
        return ans;
    }
};