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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int> indegree;
        unordered_map<int,TreeNode*> mp;
        for(auto it : descriptions){
            TreeNode* parent,*child;
            if(mp.find(it[0])!=mp.end())
                parent = mp[it[0]];
            else{
                parent = new TreeNode(it[0]);
                mp[it[0]] = parent;
            }
            if(mp.find(it[1])!=mp.end()){
                child = mp[it[1]];
            }
            else{
                child = new TreeNode(it[1]);
                mp[it[1]] = child;
            }
            indegree[it[1]]++;
            if(it[2])
                parent->left = child;
            else
                parent->right = child;
        }

        for(auto it:mp){
            if(indegree[it.first]==0)
                return mp[it.first];
        }
        return NULL;
    }
};