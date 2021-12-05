// Ques: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
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
    vector<int> path1, path2;
    
    void dfs(TreeNode *root, int x, int y, vector<int> &path) {
        if(!root)
            return;
        
        path.push_back(root->val);
        if(root->val==x) 
            path1 = path;
        if(root->val==y)
            path2 = path;
        dfs(root->left, x, y, path);
        dfs(root->right, x, y, path);
        path.pop_back();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        path1.clear(), path2.clear();
        vector<int> path;
        dfs(root, startValue, destValue, path);
        // for(auto it:path1) cout<<it<<" "; cout<<endl;
        // for(auto it:path2) cout<<it<<" "; cout<<endl;
        int i1=0, i2=0, lca;
        
        TreeNode *tmp = NULL;
        while(i1<path1.size() && i2<path2.size() && path1[i1]==path2[i2]) {
            if(tmp==NULL) {
                tmp = root;
            } else if(tmp->left && tmp->left->val==path1[i1])
                tmp = tmp->left;
            else tmp = tmp->right;
            lca = tmp->val;
            i1++, i2++;
        }
        i1--, i2--;
        
        // cout<<i1<<" "<<i2<<" "<<lca<<" "<<tmp->val<<endl;
        
        
        string ans = "";
        while(i1<path1.size()-1)
            ans += 'U', i1++;
        
        while(i2<path2.size()-1) {
            if(tmp->left && tmp->left->val==path2[i2+1]) {
                ans += 'L';
                i2++, tmp = tmp->left;
            } else {
                ans += 'R';
                i2++, tmp = tmp->right;
            }
        }
        
        return ans;
    }
};