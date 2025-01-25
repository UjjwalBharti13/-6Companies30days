class Solution {
public:

// Approach 
 // It is a classic sliding window problem
 // we can store each element freq in map and check iys freq is <=k 
 // and count result 

    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
          
            unordered_map<int,int> mp;
              
               int i=0;
               int j=0;

                   int count=0;

                     while(j<n){
                            mp[nums[j]]++;

                            while(i<j and mp[nums[j]]>k){
                                  mp[nums[i]]--;
                                  i++;
                            }
                               count  = max(count, j-i+1);
                               j++;
                     }
                     return count;
    }
};
