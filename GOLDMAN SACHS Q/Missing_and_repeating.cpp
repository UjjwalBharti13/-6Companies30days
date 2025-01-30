class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int repeating = -1, missing = -1;
        
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                repeating = arr[i];
                break;
            }
        }
        
        vector<bool> present(n + 1, false);
        for (int i = 0; i < n; i++) {
            present[arr[i]] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            if (!present[i]) {
                missing = i;
                break;
            }
        }
        
        return {repeating, missing};
    }
};
