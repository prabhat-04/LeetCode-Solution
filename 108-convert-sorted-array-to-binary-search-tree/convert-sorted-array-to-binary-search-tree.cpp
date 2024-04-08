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
    TreeNode* help(vector<int> &nums,int l,int r){
        if(l>r) return NULL;
        // if(r-l==1) return new TreeNode(nums[l]);
        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = help(nums,l,mid-1);
        root->right = help(nums,mid+1,r);
        return root;

    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return nullptr;
        return help(nums,0,nums.size()-1);
    }
};