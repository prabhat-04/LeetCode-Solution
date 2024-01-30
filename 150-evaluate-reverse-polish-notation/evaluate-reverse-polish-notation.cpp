class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operatorStack;
        int l = tokens.size();
    
        for(int i=0;i<l;i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||tokens[i] == "/"){
                int operator2 = operatorStack.top();
                operatorStack.pop();
                int operator1 =  operatorStack.top();
                operatorStack.pop();

                int tempResult;
                if(tokens[i] == "+"){
                    tempResult = (operator1 + operator2);
                }
                else if(tokens[i] == "-"){
                    tempResult = (operator1 - operator2);
                }
                else if(tokens[i] == "*"){
                    tempResult = (operator1 * operator2);
                }
                else if(tokens[i] == "/"){
                    tempResult = (operator1 / operator2);
                }

                operatorStack.push(tempResult);

            }
            else{
                operatorStack.push(stoi(tokens[i]));
            }
        }

        return operatorStack.top();
    }
};