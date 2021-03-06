class Solution {
public:
    bool isMatch(string s, string p) {
        bool** dp = new bool*[(p.size()+1)];
        for(int i = 0; i <= p.size(); i++){
            dp[i] = new bool[(s.size()+1)];
        }
        
        //Traversing the DP Array 
        for(int i = 0; i <= p.size(); i++){
            for(int j = 0; j <= s.size(); j++){
                //0-0 cell
                if(i==0 && j==0){
                    dp[i][j] = true;
                }
                //first row
                else if(i == 0){
                    dp[i][j] = false;
                }
                //first column
                else if(j == 0){
                    if(p[i-1] == '*'){
                        dp[i][j]=dp[i-1][j];
                    }
                    else
                    dp[i][j] = false;
                }
                //rest of the cells
                else{
                    char current = p[i-1];
                    if(current == '?'){
                        dp[i][j] = (dp[i-1][j-1]);
                    }
                    else if(current == '*'){
                        dp[i][j] = (dp[i-1][j] || dp[i][j-1]); 
                    }
                    else{
                        if(p[i-1] == s[j-1]){
                            dp[i][j] = dp[i-1][j-1];
                        }
                        else{
                            dp[i][j] = false;
                        }
                    }
                }
            }
        }
        // cout << dp[p.size()][s.size()];
        return dp[p.size()][s.size()];
    }
};