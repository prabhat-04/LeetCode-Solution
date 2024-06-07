class Solution {
    public String getPermutation(int n, int k) {
        StringBuilder str = new StringBuilder();
        boolean[] vis = new boolean[n];
        int[] cnt = {0};
        StringBuilder ans = new StringBuilder();
        rec(n, k, vis, str, cnt, ans);
        return ans.toString();
    }

    private void rec(int n, int k, boolean[] vis, StringBuilder str, int[] cnt, StringBuilder ans) {
        if (str.length() == n) {
            cnt[0]++;
            if (cnt[0] == k) {
                ans.append(str.toString());
                return;
            }
        }

        for (int j = 0; j < n; j++) {
            if (!vis[j]) {
                str.append((char) (j + '1'));
                vis[j] = true;
                rec(n, k, vis, str, cnt, ans);
                if (ans.length() > 0) {
                    return;  // Found the answer, no need to continue
                }
                vis[j] = false;
                str.deleteCharAt(str.length() - 1);
            }
        }
    }
}
