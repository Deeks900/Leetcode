class Solution {
public:
    int findTheLongestSubstring(string s) {
        int mask = 0;
        vector<int> dp(32, s.size());
        dp[0] = -1;
        int len = 0;
        string temp = "aeiou";
        for(int i = 0; i < s.size(); i++){
            int index = ((1<<(temp.find(s[i])+1))>>1);
            mask = (mask^index);
            len = max(len, i-dp[mask]);
            dp[mask] = min(i, dp[mask]);
        }
        
        
        return len;
    }
};