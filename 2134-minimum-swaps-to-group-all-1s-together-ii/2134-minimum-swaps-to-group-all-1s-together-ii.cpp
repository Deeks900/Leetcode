class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1){
            return 0;
        }
        
        //Count the total number of 1s in the given array
        int countOnes = 0;
        for(auto i: nums){
            if(i == 1){
                countOnes++;
            }
        }
        
        //This will be storing the minimum count
        int res = INT_MAX;
        
        //Now start sliding the window to check contiguous region of length count that has the most 1s in it.
        for(int i = 0, j = 0, count = 0; i < n; i++){
            //Increase j upto the length countOnes
            while(j-i < countOnes){
                count += nums[j++%n];
            }
            res = min(res, countOnes-count);
            //Window is moved one step forward so decrease the nums[i] present at previous step that was eliminated
            count -= nums[i];
        }
        
        return res;
    }
};