class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // int num1Idx = 0, num2Idx = 0;
        for(int i=m;i<m+n;i++)
            nums1[i] = nums2[i-m];
        sort(nums1.begin(), nums1.end());
            
    }
};