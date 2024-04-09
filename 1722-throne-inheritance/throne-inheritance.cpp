class ThroneInheritance {
struct node{
    string name;
    vector<node*> child;
    bool isAlive=true;
    node(string me){
        name = me;
        isAlive = true;
    }
};
unordered_map<string,node*> mp;
node *king=NULL;
public:
    ThroneInheritance(string kingName) {
        king  = new node(kingName);
        mp[kingName] = king;
    }
    
    void birth(string parentName, string childName) {
        node *temp = new node(childName);
        mp[parentName]->child.push_back(temp);
        mp[childName] = temp;
    }
    
    void death(string name) {
        mp[name]->isAlive = false;
    }

    void help(node *king,vector<string> &ans){
        if(!king) return;
        if(king->isAlive) ans.push_back(king->name);
        for(int i=0;i<king->child.size();i++){
            help(king->child[i],ans);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        help(king,ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */