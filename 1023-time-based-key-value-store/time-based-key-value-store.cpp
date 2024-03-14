class TimeMap {
public:
   unordered_map<string,map<int,string,greater<int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string val, int timestamp) {
         mp[key][timestamp] = val;
    }
    
    string get(string key, int timestamp) {
         if(mp.count(key) ==0) return "";

        auto itr =mp[key]. lower_bound(timestamp);

        if(itr == mp[key].end()) return "";

        return itr->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */