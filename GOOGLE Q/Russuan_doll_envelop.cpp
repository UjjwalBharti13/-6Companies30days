class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort the envelopes by width in ascending order.
        // If widths are the same, sort by height in descending order.
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        // Use a vector to store the heights for the LIS calculation.
        vector<int> dp;

        for (const auto& envelope : envelopes) {
            // Find the position where the current height can replace or extend.
            auto it = lower_bound(dp.begin(), dp.end(), envelope[1]);
            if (it == dp.end()) {
                dp.push_back(envelope[1]);
            } else {
                *it = envelope[1];
            }
        }

        return dp.size();
    }
};
