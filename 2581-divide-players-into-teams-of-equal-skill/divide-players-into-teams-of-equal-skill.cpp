class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if(skill.empty()) return -1;
        sort(skill.begin(),skill.end());
        int i=1,j=skill.size()-2;
        long long ans = skill[0]*skill[skill.size()-1],curr=0;
        int temp = skill[0]+skill[skill.size()-1];
        while(i<j){
            if(skill[i]+skill[j]!=temp) return -1;
            ans += (skill[i]*skill[j]);
            i++;
            j--;
        }
        return ans;
    }
};