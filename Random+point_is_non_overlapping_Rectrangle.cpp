class Solution {
public:

    vector<vector<int> > rectangles;
    int totalArea;
    map<int,int> areaToIdx;

    Solution(vector<vector<int>> rects) {
       rectangles = rects;
       totalArea = 0;
       for (auto& x : rectangles) {
          // We add 1 because we can choose values on the border.
          totalArea += (x[2] - x[0] + 1) * (x[3] - x[1] + 1);
          areaToIdx.insert({totalArea, areaToIdx.size()});
       }
    }

    vector<int> pick() {
       int value = rand() % totalArea;
       int idx = areaToIdx.upper_bound(value)->second;
       int width = rectangles[idx][2] - rectangles[idx][0] + 1;
       int height = rectangles[idx][3] - rectangles[idx][1] + 1;
       return {
          rand() % width + rectangles[idx][0],
          rand() % height + rectangles[idx][1]
       };
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
