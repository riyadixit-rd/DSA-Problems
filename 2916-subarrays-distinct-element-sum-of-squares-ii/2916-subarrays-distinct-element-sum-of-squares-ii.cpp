class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<long long> sum, lazy;

    void apply(int node, int l, int r, long long v) {
        long long len = r - l + 1;
        sum[node] = (sum[node] + 2 * v % MOD * sumLen[node] % MOD
                     + v * v % MOD * len) % MOD;
        lazy[node] = (lazy[node] + v) % MOD;
        sumLen[node] = (sumLen[node] + v * len) % MOD;
    }

    vector<long long> sumLen;

    void push(int node, int l, int r) {
        if (!lazy[node] || l == r) return;
        int mid = (l + r) / 2;
        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);
        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);
        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        sumLen[node] = (sumLen[node * 2] + sumLen[node * 2 + 1]) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum.assign(4 * n, 0);
        sumLen.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            update(1, 0, n - 1, last[nums[i]] + 1, i);
            last[nums[i]] = i;
            ans = (ans + sum[1]) % MOD;
        }
        return ans;
    }
};