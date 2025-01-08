class Solution {
public:
    pair<string, int> helper(vector<int>& arr, int i, int j, vector<vector<pair<string, int>>>& dp) {
        if (i == j) {
            string st = "";
            st += 'A' + (i - 1);
            return {st, 0};
        }
        if (dp[i][j].second != -1) return dp[i][j];
        
        int mn = INT_MAX;
        string sr = "";
        for (int k = i; k < j; k++) {
            auto curr1 = helper(arr, i, k, dp);
            auto curr2 = helper(arr, k + 1, j, dp);
            
            int cost = curr1.second + curr2.second + arr[i - 1] * arr[k] * arr[j];
            string s = "(" + curr1.first + curr2.first + ")";
            if (cost < mn) {
                mn = cost;
                sr = s;
            }
        }
        dp[i][j] = {sr, mn};
        return dp[i][j];
    }
    
    string matrixChainOrder(vector<int>& arr) {
        int n = arr.size();
        vector<vector<pair<string, int>>> dp(n, vector<pair<string, int>>(n, {"", -1}));
        
        auto ans = helper(arr, 1, n - 1, dp);
        return ans.first;
    }
};
