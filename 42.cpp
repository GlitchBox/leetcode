class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size()==0)
            return 0;
        
        int left = 0, right = height.size() - 1;
        int leftMost = height[left], rightMost = height[right];
        int trapped = 0;
        
        while(left < right){
            
            if(height[left]<height[right]){
                
                if(height[left]>leftMost)
                    leftMost = height[left];
                else
                    trapped += (leftMost - height[left]);
                left++;
            }
            else{
                
                if(height[right]>rightMost)
                    rightMost = height[right];
                else
                    trapped += (rightMost- height[right]);
                right--;
            }
        }
        return trapped;
    }
};