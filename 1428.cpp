/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        vector<int> rowCols = binaryMatrix.dimensions();
        int ret = -1;
        
        //for each row, binray search through all the columns for 1
        for(int r=0;r<rowCols[0];r++){
            
            int b = 0, e = rowCols[1] - 1;
            while(b<=e){
                
                int mid = (b+e)/2;
                int val = binaryMatrix.get(r, mid);
                if(val==1)
                    e = mid - 1;
                else
                    b = mid + 1;
            }
            if(b < rowCols[1]){
                if(ret == -1 || b<ret)
                    ret = b;
            }
        }
        
        return ret;
    }
};

//alternate solution
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        vector<int> rowCols = binaryMatrix.dimensions();
        
        int row = rowCols[0] - 1, col = rowCols[1] - 1;
        while(row>-1 && col>-1){
            
            if(binaryMatrix.get(row, col) == 1)
                col-=1;
            else
                row-=1;
        }
        
        
        return (col==rowCols[1]-1)?-1:col+1;
    }
};