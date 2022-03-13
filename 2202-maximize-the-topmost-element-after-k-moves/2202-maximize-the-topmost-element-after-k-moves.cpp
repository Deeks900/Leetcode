class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        
        //First Case:If the size of the vector is one
        if(n == 1){
            //if k is even
            if((k&1) == 0){
                return nums[0];
            }
            //if K is odd
            else{
                return -1;
            }
        }
        
        //Second Case: If the size of the vector is less than K
        if(k > n){
            int maxAns = INT_MIN;
            for(auto i: nums){
                maxAns = max(maxAns, i);
            }
            ans = maxAns;
            return ans;
        }
        
        //Third Case: If the size of the vector is equal to K
        if(k == n){
            int maxAns = INT_MIN;
            for(int i = 0; i < k-1; i++){
                maxAns = max(maxAns, nums[i]);
            }
            ans = maxAns;
            return ans;
        }
        
        //Fourth Case
        if(k < n){
            int maxAns = INT_MIN;
            for(int i = 0; i < k-1; i++){
                maxAns = max(maxAns, nums[i]);
            }
             ans = max(maxAns, nums[k]);
        }
        return ans;
    }
};