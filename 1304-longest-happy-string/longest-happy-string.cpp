class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int currA=0,currB=0,currC=0;
        string ans="";
        int temp=a+b+c;
        for(int i=0;i<temp;i++){
            if((a>=b && a>=c && currA!=2) or (a>0 and (currB==2 or currC==2))){
                ans+='a';
                a--;
                currA++;
                currB=0;
                currC=0;
            }
            else if((b>=a and b>=c and currB!=2) or (b>0 and(currC==2 or currA==2))){
                ans+='b';
                b--;
                currB++;
                currA=0;
                currC=0;
            }
            else if((c>=a and c>=b and currC!=2) or (c>0 and (currA==2 or currB==2))){
                ans+='c';
                c--;
                currC++;
                currB=0;
                currA=0;
            }
        }
        return ans;
    }
};