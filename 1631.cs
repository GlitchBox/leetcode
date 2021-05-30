public class Solution {
    
    long maxVal = 2000000001;
    long [,]distance = new long[105,105];
    
    public bool findMinEffort(int r1, int c1, int r2, int c2, int[][] heights){
        long minEffort = 0;
        if(r1!=0 || c1!=0)
            minEffort = Math.Max((long)Math.Abs(heights[r1][c1]-heights[r2][c2]), distance[r1,c1]);
        else
            minEffort = (long)Math.Abs(heights[r1][c1]-heights[r2][c2]);
        if(minEffort < distance[r2,c2]){
            distance[r2,c2] = minEffort;
            return true;
        }
        return false;
    }
    
    public int MinimumEffortPath(int[][] heights) {
        
        int rows = heights.Length, cols = heights[0].Length;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++)
                distance[i,j] = maxVal;
        }
        distance[0,0] = 0;
        
        int nodes = rows*cols;
        for(int times=0;times<nodes-1;times++){
            bool ifChanged = false;
            
            for(int r=0;r<rows;r++){
                for(int c=0;c<cols;c++){
                    
                    //go below
                    if(r<rows-1)
                        ifChanged |= findMinEffort(r,c,r+1,c, heights);
                    //go upwards
                    if(r>0)
                        ifChanged |= findMinEffort(r,c,r-1,c, heights);
                    //go right
                    if(c<cols-1)
                        ifChanged |= findMinEffort(r,c,r,c+1, heights);
                    //go left
                    if(c>0)
                        ifChanged |= findMinEffort(r,c,r,c-1, heights);
                }
            }
            
            if(ifChanged == false)
                break;
        }
        
        return (int)distance[rows-1,cols-1];
    }
}