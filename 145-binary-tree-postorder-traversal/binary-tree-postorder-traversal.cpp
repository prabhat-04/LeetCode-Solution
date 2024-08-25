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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<pair<TreeNode*,bool>> st;
        st.push({root,false});
        while(!st.empty()){
            auto curr = st.top();
            st.pop();
            if(curr.second){
                ans.push_back(curr.first->val);
            }
            else{
                st.push({curr.first,true});
                if(curr.first->right) st.push({curr.first->right,false});
                if(curr.first->left) st.push({curr.first->left,false});
                
            }
        }
        return ans;
    }
};