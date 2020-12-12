class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        int ret = 0;
        int n = candyType.size();
        int distinct[200010];
        memset(distinct, 0, sizeof(distinct));
        
        for(int i=0;i<n;i++){
            
            if(ret==n/2)
                return ret;
            
            if(candyType[i]>=0){
                if(!distinct[candyType[i]]){
                    ret++;
                    distinct[candyType[i]] = 1;
                }
            }
            else{
                if(!distinct[-1*candyType[i] + 100000]){
                    ret++;
                    distinct[-1*candyType[i] + 100000] = 1;
                }
            }
        }
        
        return ret;
    }
};