class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),[&](auto &a,auto &b){return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});
        
        int n = arr.size();
        
        vector<vector<int>> dp;
        
        for(int i=0;i<n;i++){
     auto lb = lower_bound(dp.begin(),dp.end(),arr[i],[&](auto &a, auto &b){return (a[1] < b[1]) and (a[0] < b[0]);});
            if(lb == dp.end())
                dp.push_back(arr[i]);
            else
                *lb = arr[i];
        }
        
        return dp.size()-1;
    }
};
