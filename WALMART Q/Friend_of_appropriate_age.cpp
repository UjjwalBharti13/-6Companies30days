class Solution {
public:
  bool solve(int a, int b){
     return !(b<=0.5*a+7 or b>a or (b>100 and a<100));
  }
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int> mp;
           for( auto ele : ages){
                  mp[ele]++;
           }
         int ans=0;
            for( auto a : mp){
                 for( auto b: mp){
                     if(solve(a.first,b.first)){
                         ans += a.second*(b.second-(a.first==b.first?1:0));
                     }
                 }
            }
              return ans;

    }
};
