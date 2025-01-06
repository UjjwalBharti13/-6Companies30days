class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
             x1 -= xCenter;
             x2 -= xCenter;
             y1 -= yCenter;
             y2 -= yCenter;

                int min_x = (x1*x2>0)?min(x1*x1, x2*x2):0;
                int min_y = (y1*y2>0)?min(y1*y1, y2*y2):0;
                 
                  return min_x+min_y<=radius*radius;
    }
};
