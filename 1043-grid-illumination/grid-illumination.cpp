class Solution {
    unordered_map<int,int>row,col,posDig,negDig;
    set<pair<int,int>>litLamps;
public:
    bool isLit(int i,int j ){
        if(row[i]!=0 || col[j]!=0 || posDig[i+j]!=0 || negDig[i-j]!=0)return true;
        return false;
    }
    
    void offTheBulb(int i,int j,int n){
        if(i<0 || j<0 || i>=n || j>=n)return ;
        if(litLamps.find({i,j})==litLamps.end())return ;
        litLamps.erase({i,j});
        row[i]--;
        col[j]--;
        posDig[i+j]--;
        negDig[i-j]--;
        return ;
    }
    
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int>res(queries.size(),0);
        int size=lamps.size();
        
        for(int i=0;i<size;i++){
            if(litLamps.find({lamps[i][0],lamps[i][1]})!=litLamps.end())continue;
            litLamps.insert({lamps[i][0],lamps[i][1]});
            row[lamps[i][0]]++;
            col[lamps[i][1]]++;
            posDig[lamps[i][0]+lamps[i][1]]++;
            negDig[lamps[i][0]-lamps[i][1]]++;
        }
        
        for(int i=0;i<queries.size();i++){
            int q1=queries[i][0],q2=queries[i][1];
            
            if(isLit(q1,q2))res[i]=1;
            
            offTheBulb(q1,q2,n);
            offTheBulb(q1+1,q2,n);
            offTheBulb(q1,q2+1,n);
            offTheBulb(q1+1,q2+1,n);
            offTheBulb(q1-1,q2,n);
            offTheBulb(q1,q2-1,n);
            offTheBulb(q1-1,q2-1,n);
            offTheBulb(q1-1,q2+1,n);
            offTheBulb(q1+1,q2-1,n);

            
            
        }
        return res;
    }
};