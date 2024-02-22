class Solution {
public:
    void rec(int i,string tiles,int &count){
        if(i>=tiles.size()) return;
        vector<bool> vis(256,false);
        for(int j=i;j<tiles.size();j++){
            if(vis[tiles[j]]) continue;
            vis[tiles[j]] = true;
            swap(tiles[i],tiles[j]);
            rec(i+1,tiles,count);
            count++;
            swap(tiles[i],tiles[j]);
        }
    }

    int numTilePossibilities(string tiles) {
        int count = 0;
        rec(0,tiles,count);
        return count;
    }
};