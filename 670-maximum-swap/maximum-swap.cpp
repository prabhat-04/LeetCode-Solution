class Solution {
public:
    int maximumSwap(int num) {
        vector<int> vec(10,-1);
        string str = to_string(num);
        for(int i=0;i<str.size();i++){
            vec[str[i]-'0']=i;
        }
        for(int i=0;i<str.size();i++){
            for(int j=9;j>str[i]-'0';j--){
                if(vec[j]>i){
                    swap(str[i],str[vec[j]]);
                    return stoi(str);
                }
            }
        }
        return num;

    }
};