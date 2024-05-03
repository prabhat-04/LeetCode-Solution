class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        int n = version1.size(),m=version2.size();
        while(i<n || j<m){
            string cur1="";
            string cur2="";
            while(i<n && version1[i]!='.'){
                cur1+=version1[i];
                i++;
            }
            while(j<m && version2[j]!='.'){
                cur2+=version2[j];
                j++;
            }
            if(cur1=="") cur1="0";
            if(cur2=="") cur2="0";
            int p = stoi(cur1);
            int q = stoi(cur2);
            if(p>q) return 1;
            if(p<q) return -1;
            i++;
            j++;
        }
        return 0;
    }
};