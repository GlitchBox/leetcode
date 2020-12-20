class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        int rows = A.size(), cols = A[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols/2;j++){
                
                int temp = A[i][j];
                A[i][j] = A[i][cols-1-j];
                A[i][cols-1-j] = temp;
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++)
                A[i][j] = (A[i][j]+1)%2;
        }
        
        return A;
        
    }
};