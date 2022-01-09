class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes = 0, n = nums.size();
        //here totalOnes is the number of 1's present in array
        for (auto it : nums){
            if (it == 1)
                totalOnes++;
        }
        
		
        //now we will count the maximum number of 1's in any window of size totalOnes
        int maxOnesInWindow = 0, onesInCurrWindow = 0, i = 0;
        for (i = 0; i < totalOnes; i++){
            if (nums[i] == 1)
                maxOnesInWindow++;
        }
        
        //onesInCurrWindow is the count of 1's in the current window
		onesInCurrWindow = maxOnesInWindow;
		
        //Now we will move the array with a constant window size of totalOnes
        for (; i < n + totalOnes-1; i++){
            //In this step we are moving window forward by one step
            //if nums[i%n] is 1 then add 1 to onesInCurrWindow
            //if nums[i - totalOnes] is 1 then subtrct 1 from onesInCurrWindow
            onesInCurrWindow += (nums[i % n] - nums[i - totalOnes]);
            maxOnesInWindow = max(onesInCurrWindow, maxOnesInWindow);
        }
        return totalOnes - maxOnesInWindow; 
    }
};