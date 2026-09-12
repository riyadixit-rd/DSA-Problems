import java.util.*;

class Solution {
    static class State {
        long score;
        int[] ids;

        State(long score, int[] ids) {
            this.score = score;
            this.ids = ids;
        }
    }

    public int[] maximumWeight(List<List<Integer>> intervals) {
        int n = intervals.size();

        Integer[] order = new Integer[n];

        for (int i = 0; i < n; i++) {
            order[i] = i;
        }

        Arrays.sort(order, (a, b) -> {
            int ea = intervals.get(a).get(1);
            int eb = intervals.get(b).get(1);

            if (ea != eb) return Integer.compare(ea, eb);
            return Integer.compare(a, b);
        });

        int[] ends = new int[n];

        for (int i = 0; i < n; i++) {
            ends[i] = intervals.get(order[i]).get(1);
        }

        int[] prev = new int[n];

        for (int i = 0; i < n; i++) {
            int start = intervals.get(order[i]).get(0);

            int l = 0, r = i - 1;
            int p = -1;

            while (l <= r) {
                int mid = (l + r) >>> 1;

                if (ends[mid] < start) {
                    p = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            prev[i] = p;
        }

        State[][] dp = new State[n + 1][5];

        for (int i = 0; i <= n; i++) {
            for (int k = 0; k <= 4; k++) {
                dp[i][k] = new State(0, new int[0]);
            }
        }

        for (int i = 1; i <= n; i++) {
            int idx = order[i - 1];
            long weight = intervals.get(idx).get(2);

            for (int k = 1; k <= 4; k++) {
                State skip = dp[i - 1][k];

                State base = dp[prev[i - 1] + 1][k - 1];

                int[] ids = Arrays.copyOf(base.ids, base.ids.length + 1);
                ids[ids.length - 1] = idx;

                Arrays.sort(ids);

                State take = new State(base.score + weight, ids);

                dp[i][k] = better(skip, take);
            }
        }

        State ans = dp[n][0];

        for (int k = 1; k <= 4; k++) {
            ans = better(ans, dp[n][k]);
        }

        return ans.ids;
    }

    private State better(State a, State b) {
        if (a.score != b.score) {
            return a.score > b.score ? a : b;
        }

        for (int i = 0; i < Math.min(a.ids.length, b.ids.length); i++) {
            if (a.ids[i] != b.ids[i]) {
                return a.ids[i] < b.ids[i] ? a : b;
            }
        }

        return a.ids.length <= b.ids.length ? a : b;
    }
}