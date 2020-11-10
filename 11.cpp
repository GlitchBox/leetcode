//two pointer approach
class Solution {
public:

    //two pointer approach
    int maxArea(vector<int>& height) {
        int len = height.size();
        int l=0, r =len-1;
        int i=0,j=len-1;
        int output = (r-l)*min(height[l], height[r]);
        
        while(i<j){
            if(height[i]<height[j])
                i++;
            else
                j--;
            
            int temp = (j-i)*min(height[i], height[j]);
            if(temp>output){
                output = temp;
                r = j;
                l = i;
            }
        }
   
        return output;
    }
};