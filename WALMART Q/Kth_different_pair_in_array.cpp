class Solution {
public:
   // optimal approach
    int solve (vector<int>& nums, int k) {
        if (k < 0) return 0;
         
            unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        int ans = 0;
        for (auto& [num, count] : freq) {
            if (k == 0) {
                // Special case: k = 0, count the number of elements that appear at least twice
                if (count > 1) {
                    ans++;
                }
            } else {
                // General case: check if num + k exists
                if (freq.count(num + k)) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
      
      //  Brute Force
int helper(vector<int>& nums, int k){
     int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
         //  Brute Force 
         for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (nums[j] - nums[i] == k) {
                           ans++;
                           break; 
                     } 
                else if (nums[j] - nums[i] > k) {
                    break;
                }
            }
            
        }
         return ans;
}
       
    int findPairs(vector<int>& nums, int k) {
            
            // Brute Force 
           //  return helper(nums,k);
             // optimal approach
            return solve(nums,k);  
    }  
    
};
