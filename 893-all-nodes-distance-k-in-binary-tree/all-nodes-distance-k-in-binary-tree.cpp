/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void help(TreeNode* root,TreeNode* target,unordered_map<TreeNode*,TreeNode*> &parent){
        if(!root) return;
        // if(root==target) return;
        if(root->left){
            parent[root->left]=root;
            help(root->left,target,parent);
        }
        if(root->right){
            parent[root->right]=root;
            help(root->right,target,parent);
        }
    }
    vector<int> bfs(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &parent,int k){
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        unordered_set<TreeNode*> s;
        s.insert(root);
        while(!q.empty() && k>0){
            k--;
            int size= q.size();
            for(int i=0;i<size;i++){
                auto curr = q.front();
                // cout<<curr->val<<endl;
                q.pop();
                if(curr->left && s.find(curr->left)==s.end()){ 
                    q.push(curr->left);
                    s.insert(curr->left);
                }
                if(curr->right && s.find(curr->right)==s.end()){
                    q.push(curr->right);
                    s.insert(curr->right);
                }
                if(parent[curr] && s.find(parent[curr])==s.end()){
                    q.push(parent[curr]);
                    s.insert(parent[curr]);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            // cout<<q.front()->val<<endl;
            q.pop();
        }
        return ans;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root|| !target) return {};
        unordered_map<TreeNode*,TreeNode*> parent;
        parent[root]=NULL;
        help(root,target,parent);
        return bfs(target,parent,k);
    }
};