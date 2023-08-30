class Solution {
public:
    int bestClosingTime(string customers) {
        int y = count(customers.begin(),customers.end(),'Y');
        int a=y;
        int ans = 0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y')
                y--;
            else
                y++;
            if(a>y){
                a=y;
                ans=i+1;
            }
            
        }
        return ans;
    }
};