class Solution {
public:
    // Approach: We can simply use Z-function
    vector<int> z_func(string s) {
        int n = s.size();
        vector<int> ans(n);
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i <= r) {
                ans[i] = min(r - i + 1, ans[i - l]);
            }
            while (i + ans[i] < n && s[ans[i]] == s[i + ans[i]]) {
                ans[i]++;
            }
            if (i + ans[i] - 1 > r) {
                l = i;
                r = i + ans[i] - 1;
            }
        }
        return ans;
    }

    long long sumScores(string s) {
        vector<int> arr = z_func(s);
        long long sum = s.size(); // Use long long to prevent overflow
        for (int i = 1; i < s.size(); i++) {
            sum += arr[i];
        }
        return sum;
    }
};
