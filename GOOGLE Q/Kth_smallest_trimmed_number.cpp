class Solution {
public: 
// Approach
   //  we make a map foreach pair with the triming value
   // like for 1st teimming value we take rightmost 1st element in string and store them with the index value
   // just like we perform for each trim value and after performing this we sort the map with the hellp of comparator 
   // after that we check whivh kth smallest value i have to retirn then we return the index value of that element in map

 struct Pair{
       string s;
        int index;
         Pair(string s, int index):s(s), index(index){}
 };
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
            unordered_map<int, vector<Pair>> mp;
              
              // preprocess the terminal string 
                
                 for(int i=0;i<nums.size();i++){
                       string str = nums[i];
                       int n = str.size();
                         int l=n;
                          for(int j=0;j<n;j++){
                             mp[l].emplace_back(str.substr(j),i);
                             l--;
                          }
                 }
                 vector<int> ans(queries.size());
                   int idx=0;
                    for(auto ele: queries){
                          int kthElement = ele[0];
                          int key = ele[1];

                            vector<Pair>& list = mp[key];

                            // sorting with the helpof comparatoe
                            sort(list.begin(),list.end(),[](const Pair& p1, const Pair& p2){
                                  // if both value same return early index value
                                if(p1.s==p2.s) return p1.index<p2.index;
                                  return p1.s<p2.s;
                            });
                               ans[idx++]=list[kthElement-1].index;
                    }
                     return ans;

    }
};
