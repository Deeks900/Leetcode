class Solution {
public:
    //Palindromic substrings are of two types:
    //One with each character occuring even number of times
    //Other with each character occuring even number of times except one character that is occurng odd number of times.
    
    int longestAwesome(string s) {
        int mask = 0;
        int maxLength = 0;
        //1024 combinations of mask can be there
        vector<int> dp(1024, s.size());
        dp[0] = -1;
        
        for(int i = 0; i < s.size(); i++){
            //helps in identifying that upto this index in string this character has occured even times or oddtimes
            mask ^= (1<<(s[i]-'0')); 
            //if 0 is at that place in mask it means that this digit has occured even number of times 
            //if 1 is at that place in mask it means that this digit has occured odd number of times
            
            //If this mask present already then our length will get updated
            //Case of palindromic substring with each character occuring even number of times
            maxLength = max(maxLength, i-dp[mask]);
            
            //check if this is the case with each character occuring even number of times except one character that is occurng odd number of times.
            for(int j = 0; j < 10; j++){
                //Toggling each digit one by one
                int tempMask = (mask^(1<<j));
                maxLength = max(maxLength, i-dp[tempMask]);
            }
            
            dp[mask] = min(dp[mask], i);
        }
       return maxLength; 
    }
};