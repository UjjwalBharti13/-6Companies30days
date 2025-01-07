class Solution {
    #define ll long long int 
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
          ll ans=0;
           ll sum=0;
           int start=0; 
           int n = nums.size();
            unordered_map<int,int> mp;
             
              for(int i=0;i<n;i++){
                  sum+=nums[i];
                    mp[nums[i]]++;

                    if(i-start+1==k){
                         if(mp.size()==k){
                             ans = max(ans,sum);
                         }
                         sum -= nums[start];
                          if(--mp[nums[start]]==0){
                             mp.erase(nums[start]);
                          }
                            start++;
                    }
              }
                return ans;


    }
};
