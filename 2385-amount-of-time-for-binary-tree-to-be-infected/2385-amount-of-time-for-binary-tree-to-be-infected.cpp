/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void inorder(TreeNode* root,unordered_map<int,vector<int>> &mp){
        if(root==NULL) return;
        if(root->left){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
        }
        if(root->right){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
        }
        inorder(root->left,mp);
        inorder(root->right,mp);
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        int ans=-1;
        unordered_map<int,vector<int>> mp;
        unordered_set<int> visited;
        inorder(root,mp);
        queue<int> q;
        visited.insert(start);
        q.push(start);
        while(!q.empty()){
            ++ans;
            for(int i=q.size();i>0;i--){
                int curr = q.front();
                q.pop();
                for(int x:mp[curr]){
                    if(visited.find(x)==visited.end()){
                        visited.insert(x);
                        q.push(x);
                    }
                }
            }
        }
        return ans;
    }
};