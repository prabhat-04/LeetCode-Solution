class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        int ans=0;
        int score = 0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                ans++;
                i++;
                score=max(ans,score);
            }
            else if(ans>0 ){
                power+=tokens[j];
                ans--;
                j--;
            }
            else
                break;
            
        }
        return score;
    }
};