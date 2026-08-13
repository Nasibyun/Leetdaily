class Solution {
    struct Node {
        int len, left, right, best;
        char lc, rc;
        Node() : len(0), left(0), right(0), best(0), lc(0), rc(0) {}
        Node(char c) : len(1), left(1), right(1), best(1), lc(c), rc(c) {}
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;
        res.left = a.left;
        res.right = b.right;
        res.best = max(a.best, b.best);

        if (a.rc == b.lc) {
            res.best = max(res.best, a.right + b.left);
            if (a.left == a.len) res.left = a.len + b.left;
            if (b.right == b.len) res.right = b.len + a.right;
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node] = Node(c);
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;
        int n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);

        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].best);
        }
        return ans;
    }
};