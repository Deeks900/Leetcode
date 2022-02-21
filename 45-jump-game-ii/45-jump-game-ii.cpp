class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();
    int* dp = new int[n];
    dp[n-1] = 0;

    for(int i = (n-2); i >= 0; i--){
        //if zero is present here
      
        if(arr[i] == 0){
            dp[i] = -1;
        }
        else{
            int minAns = INT_MAX;
            int jumpsAllowed = arr[i];
            for(int jump = 1; jump <= jumpsAllowed; jump++){
                if(((i+jump) < n) && (dp[i+jump] != -1)){
                    int tempAns = (1+dp[i+jump]);
                    minAns = min(minAns, tempAns);
                }
            }
            if(minAns == INT_MAX){
                dp[i] = -1;
            }
            else{
                dp[i] = minAns;
            }
            
        }  
    }
    
 return dp[0];
    }
};