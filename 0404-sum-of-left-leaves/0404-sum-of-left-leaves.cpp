class Solution {
public:
    int f(TreeNode* root,bool flag){
        if(!root) return 0;
        if(!root->left && !root->right)
            return flag? root->val : 0;
        return (f(root->right,false) + f(root->left,true));
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return f(root,false);
    }
};