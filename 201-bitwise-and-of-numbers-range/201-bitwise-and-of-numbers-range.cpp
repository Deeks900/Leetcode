class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
//         int ans = left;
//         for(int i = left+1; i<= right; i++){
//             ans = (ans&i);
            
//         }
//         return ans;
        int res = left;
        
        for(long long  i = (long)left+1; i <= right; i++)
        {
            res = (res & i);
            
            if(res == 0)
                return 0;
        }
        
        return res;
    }
};

