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
    int minSwaps(vector<int>&nums){
	    vector<pair<int,int>> copy;
	    for(int i=0;i<nums.size();i++){
	        copy.push_back({nums[i],i});
	    }
	    sort(copy.begin(),copy.end());
	    int i=0,ans=0;
	    while(i<copy.size()){
	        if(i==copy[i].second){
	            i++;
	            continue;
	        }
	        else{
	            swap(copy[i],copy[copy[i].second]);
	            ans++;
	        }
	    }
	    return ans;
	}
public:
    int minimumOperations(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> temp;
            for(int i=0;i<sz;i++){
                auto curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans += minSwaps(temp);
        }
        return ans;
    }
};