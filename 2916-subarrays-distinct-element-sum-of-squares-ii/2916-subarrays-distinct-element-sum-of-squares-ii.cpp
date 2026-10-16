class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sum_sq = 0;
        long long lazy = 0;
    };

    int n;
    vector<Node> tree;

    void push(int node, int l, int r) {
        if (tree[node].lazy != 0) {
            long long v = tree[node].lazy;
            int mid = (l + r) / 2;
            
            // Left child
            int left = 2 * node;
            tree[left].sum_sq = (tree[left].sum_sq + 2 * v * tree[left].sum + v * v % MOD * (mid - l + 1)) % MOD;
            tree[left].sum = (tree[left].sum + v * (mid - l + 1)) % MOD;
            tree[left].lazy = (tree[left].lazy + v) % MOD;

            // Right child
            int right = 2 * node + 1;
            tree[right].sum_sq = (tree[right].sum_sq + 2 * v * tree[right].sum + v * v % MOD * (r - mid)) % MOD;
            tree[right].sum = (tree[right].sum + v * (r - mid)) % MOD;
            tree[right].lazy = (tree[right].lazy + v) % MOD;

            tree[node].lazy = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long v) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            tree[node].sum_sq = (tree[node].sum_sq + 2 * v * tree[node].sum + v * v % MOD * (r - l + 1)) % MOD;
            tree[node].sum = (tree[node].sum + v * (r - l + 1)) % MOD;
            tree[node].lazy = (tree[node].lazy + v) % MOD;
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, v);
        update(2 * node + 1, mid + 1, r, ql, qr, v);
        tree[node].sum = (tree[2 * node].sum + tree[2 * node + 1].sum) % MOD;
        tree[node].sum_sq = (tree[2 * node].sum_sq + tree[2 * node + 1].sum_sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());
        
        unordered_map<int, int> last_pos;
        long long total_sum = 0;
        long long current_ans = 0;

        for (int j = 0; j < n; ++j) {
            int prev = -1;
            if (last_pos.find(nums[j]) != last_pos.end()) {
                prev = last_pos[nums[j]];
            }
            last_pos[nums[j]] = j;

            int L = prev + 1;
            int R = j;
            update(1, 0, n - 1, L, R, 1);
            current_ans = (current_ans + tree[1].sum_sq) % MOD;
        }

        return current_ans;
    }
};