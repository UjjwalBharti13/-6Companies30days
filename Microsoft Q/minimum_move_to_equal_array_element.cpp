class Solution {
public:
    int minMoves2(vector<int>& nums) {
      //sort the array first;
      sort(nums.begin(),nums.end());
      //we need to make every element equals to middle element.
      int mid=nums.size()/2;
      int need=nums[mid];
      int moves=0;//record total no. of moves required.
      for(int i=0;i<nums.size();i++)
        moves+=abs(nums[i]-need);
      return moves;
    }
};
