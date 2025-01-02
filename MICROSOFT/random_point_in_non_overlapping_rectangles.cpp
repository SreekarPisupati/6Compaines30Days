// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/submissions/1495314853/

class Solution {
public:
    vector<int> cumulativePoints;
    vector<vector<int>> rectangles;
    int totalPoints;

    Solution(vector<vector<int>>& rects) {
        rectangles = rects;
        totalPoints = 0;
        for (const auto& rect : rects) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            totalPoints += (x2 - x1 + 1) * (y2 - y1 + 1);
            cumulativePoints.push_back(totalPoints);
        }
    }

    vector<int> pick() {
        int randomPoint = rand() % totalPoints + 1;

        
        int rectangleIndex = lower_bound(cumulativePoints.begin(), cumulativePoints.end(), randomPoint) - cumulativePoints.begin();

        int x1 = rectangles[rectangleIndex][0], y1 = rectangles[rectangleIndex][1];
        int x2 = rectangles[rectangleIndex][2], y2 = rectangles[rectangleIndex][3];

        int randomX = rand() % (x2 - x1 + 1) + x1;
        int randomY = rand() % (y2 - y1 + 1) + y1;

        return {randomX, randomY};
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */