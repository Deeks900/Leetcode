class Solution {
public:
    int mod = 1e9+7;
    int distinctSubseqII(string input) {
        long* dp = new long[input.size()+1];
    dp[0] = 1;
    unordered_map<char, int> lastOccurence;
    for(int i = 1; i <= input.size(); i++){
        dp[i] = 2*dp[i-1]%mod;
        if(lastOccurence.find(input[i-1]) != lastOccurence.end()){
            int lastIndex = lastOccurence[input[i-1]];
            dp[i] -= dp[lastIndex-1];
        }
        dp[i]%=mod;
        lastOccurence[input[i-1]] = i;
    }
        dp[input.size()] -= 1;
        if(dp[input.size()] < 0){
            dp[input.size()] += mod;
        }
    return dp[input.size()];
    }
};