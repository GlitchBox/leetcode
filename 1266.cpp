class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int pointNum = points.size();
        int totalTime = 0;
        for(int i=0;i<pointNum-1;i++)
            totalTime += max( abs(points[i][0]-points[i+1][0]), abs(points[i][1]-points[i+1][1]));
        
        return totalTime;
    }
};