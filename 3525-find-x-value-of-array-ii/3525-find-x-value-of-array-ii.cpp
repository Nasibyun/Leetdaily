class Solution {
public:
    struct Node {
        int prod = 1;
        int cnt[5] = {};
    };

    int k;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;

        res.prod = (left.prod * right.prod) % k;

        for (int i = 0; i < k; i++) {
            res.cnt[i] = left.cnt[i];
        }

        for (int r = 0; r < k; r++) {
            int newR = (left.prod * r) % k;
            res.cnt[newR] += right.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            int rem = nums[l] % k;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        build(node << 1, l, mid, nums);
        build(node << 1 | 1, mid + 1, r, nums);

        tree[node] = merge(tree[node << 1], tree[node << 1 | 1]);
    }

    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            value %= k;

            tree[node].prod = value;

            for (int i = 0; i < k; i++) {
                tree[node].cnt[i] = 0;
            }

            tree[node].cnt[value] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid) {
            update(node << 1, l, mid, idx, value);
        } else {
            update(node << 1 | 1, mid + 1, r, idx, value);
        }

        tree[node] = merge(tree[node << 1], tree[node << 1 | 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) >> 1;

        if (qr <= mid) {
            return query(node << 1, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(node << 1 | 1, mid + 1, r, ql, qr);
        }

        Node left = query(node << 1, l, mid, ql, qr);
        Node right = query(node << 1 | 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        this->k = k;

        int n = nums.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};