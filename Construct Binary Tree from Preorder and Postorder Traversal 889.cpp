class Solution {
public:
    unordered_map<int, int> pos;

    TreeNode* build(vector<int>& pre, int preL, int preR, 
                vector<int>& post, int postL, int  postR){

        if (preL > preR)
            return nullptr;

        TreeNode* root = new TreeNode(pre[preL]);

        if (preL == preR)
            return root;

        int leftRoot = pre[preL + 1];

        int idx = pos[leftRoot];

        int leftSize = idx - postL + 1;

        root->left = build(pre, preL + 1, preL + leftSize, post, postL, idx);
        root->right = build(pre, preL + leftSize + 1, preR, post, idx + 1, postR - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        for (int i = 0; i < post.size(); i++)
            pos[post[i]] = i;

        return build(pre, 0, pre.size() - 1,  post, 0, post.size() - 1);
    }
};
