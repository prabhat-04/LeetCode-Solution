class Solution {
    int FindGCD(int a,int b){
        if(a==0) return b;
        return FindGCD(b%a,a);
    }
public:
    string fractionAddition(string expression) {
        int num=0;
        int denom =1;
        int i=0;
        while(i<expression.size()){
            int currNum =0;
            int currDemo = 0;
            bool isNegative = false;
            if(expression[i]=='+' || expression[i]=='-'){
                if(expression[i]=='-')
                    isNegative = true;
                i++;
            }

            while(isdigit(expression[i])){
                currNum = currNum * 10 +(expression[i]-'0');
                i++;
            }

            i++;

            while(i<expression.size() && isdigit(expression[i])){
                currDemo = currDemo *10 + (expression[i]-'0');
                i++;
            }

            if(isNegative) currNum *=-1;

            num = num * currDemo + currNum * denom;
            denom = denom * currDemo;
        }
        int gcd = abs(FindGCD(num,denom));
        num/=gcd;
        denom/=gcd;

        return to_string(num) + "/" + to_string(denom);
    }
};