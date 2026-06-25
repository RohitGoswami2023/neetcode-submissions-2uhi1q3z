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
private :
    vector<int> helper(TreeNode * node ){
        if( node == NULL) return {0 , 0};
        vector<int>left_side = helper(node->left);
        vector<int>right_side = helper(node -> right);
        vector<int> current_option(2,0);
        current_option[0] = max(left_side[0] , left_side[1]) + max(right_side[0] , right_side[1]);
        current_option[1] =  node ->val  + left_side[0] + right_side[0];
        return current_option;
    }

public:
    int rob(TreeNode* root) {
       vector<int>result  = helper(root);
        return max(result[0] , result[1]);
    }
};