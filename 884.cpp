class Solution {
public: 
    
    int maxNumberOfApples(vector<int>& arr) {

        sort(arr.begin(), arr.end());
        int ret = 0, weight = 0, idx = 0;
        for(int i=0;i<arr.size();i++){
            
            if(weight+arr[i]>5000)
                break;
            weight += arr[i];
            ret++;
        }
        
        return ret;
    }
};