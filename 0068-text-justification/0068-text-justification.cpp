class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i=0;
        while(i<words.size()){
            vector<string> currLine = getWords(i,words,maxWidth);
            i+=currLine.size();
            ans.push_back(createLine(currLine,i,words,maxWidth));
        }
        return ans;
    }

    vector<string> getWords(int i,vector<string> words,int maxWidth){
        vector<string> currentLine;
        int currLength = 0;

        while(i<words.size() && currLength + words[i].size() <= maxWidth){
            currentLine.push_back(words[i]);
            currLength += words[i].size() + 1;
            i++;
        }
        return currentLine;
    }

    string createLine(vector<string> line,int i,vector<string> words,int maxWidth){
        int baseLength = -1;
        for(auto x : line)
            baseLength += x.size() + 1;

        int extraSpaces = maxWidth - baseLength;

        if(line.size()==1)
            return line[0] + string(extraSpaces,' ');

        if(i==words.size()){
            string ans ="";
            for(int i=0;i<line.size();i++){
                if(i!=line.size()-1)
                    ans += line[i] + " ";
                else
                    ans += line[i];
            }
            ans += string(extraSpaces,' ');
            return ans;
        }

        int wordCount = line.size()-1;
        int spacesPerWord = extraSpaces/wordCount;
        int needsExtraSpace = extraSpaces % wordCount;

        

        for(int j=0;j<needsExtraSpace ;j++){
            line[j] = line[j] + " ";
        }

        for(int i=0;i<wordCount;i++){
            line[i] = line[i] + string(spacesPerWord,' ');
        }
        


        string ans ="";
        for(int i=0;i<line.size();i++){
            if(i!=line.size()-1)
                ans += line[i] + " ";
            else
                ans += line[i];
        }
        return ans;
    }
};