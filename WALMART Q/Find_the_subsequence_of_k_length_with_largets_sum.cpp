class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_min;

        for (int i = 0; i < nums.size(); i++) {
            pq_min.push({nums[i], i});
            if (pq_min.size() > k) {
                pq_min.pop();
            }
        }
        
        // Extract the k largest elements while maintaining their original indices
        vector<pair<int, int>> temp;
        while (!pq_min.empty()) {
            temp.push_back(pq_min.top());
            pq_min.pop();
        }

    
        sort(temp.begin(), temp.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });

     
        vector<int> ans;
        for (auto& p : temp) {
            ans.push_back(p.first);
        }

        return ans;
    }
};
