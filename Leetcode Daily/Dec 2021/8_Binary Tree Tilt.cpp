// https://leetcode.com/problems/binary-tree-tilt/
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
    
    int helper(TreeNode *root, int &tiltSum) {
        if(!root)
            return 0;
        int sumLeft = helper(root->left, tiltSum);
        int sumRight = helper(root->right, tiltSum);
        tiltSum += abs(sumLeft - sumRight);
        return sumLeft + sumRight + root->val;
    }
    
    int findTilt(TreeNode* root) {
        int tiltSum = 0;
        helper(root, tiltSum);
        return tiltSum;
    }
};