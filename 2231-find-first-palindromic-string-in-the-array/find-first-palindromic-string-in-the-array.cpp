class Solution {
public:
    bool palindrome(string &word){
        int i=0,j=word.size()-1;
        while(i<j){
            if(word[i]!=word[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        for(string word:words){
            if(palindrome(word))
                return word;
        }
        return "";
    }
};