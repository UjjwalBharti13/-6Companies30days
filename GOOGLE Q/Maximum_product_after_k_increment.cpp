class Solution {
public:
     int mod=pow(10,9)+7;
     #define ll long long int 
    int maximumProduct(vector<int>& nums, int k) {
         int n = nums.size();
           
            priority_queue<int, vector<int>, greater<int>> pq_min;
              
                for(int i=0;i<n;i++){
                      pq_min.push(nums[i]);
                }
                   while(k>0){
                      int curr = pq_min.top();
                       pq_min.pop();
                         curr++;
                         pq_min.push(curr);
                         k--;
                   }
                   ll ans=1;
                    while(!pq_min.empty()){ 
                          int curr = pq_min.top();
                          pq_min.pop();
                          ans = (ans*curr)%mod;
                    }
                      return ans;

    }
};
