// https://leetcode.com/problems/circle-and-rectangle-overlapping/submissions/1493479285/

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        
       int nearest_x = max(x1, min(x2,xCenter));
       int nearest_y = max(y1, min(y2,yCenter));

       int x_sqr = (xCenter-nearest_x)*(xCenter-nearest_x);
       int y_sqr = (yCenter-nearest_y)*(yCenter-nearest_y);

       if(sqrt(x_sqr+y_sqr)<=radius){
        return true;
       }
       
        return false;
       
    }

    
};