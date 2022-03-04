class Solution {
public:
    
    int lcs(vector<int>&arr, int n){
    int* dp = new int[n];
    int finalAns = INT_MIN;
    for(int i = 0; i < n; i++){
        dp[i] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = (i-1); j >= 0; j--){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], (dp[j]+1));
            }
        }
        finalAns = max(finalAns, dp[i]);
       
    }
         return finalAns;
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return lcs(nums, n);
        
    }
};