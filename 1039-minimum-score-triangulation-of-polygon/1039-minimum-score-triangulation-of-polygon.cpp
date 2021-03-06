class Solution {
public:
    int minScoreHelper(vector<int>& values, int i, int j, int** dp){
        //Base Case1
        if(i == j){
            return 0;
        }
        
        //Base Case2
        if((j-i) == 1){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        //Recursive Calls
        int finalAns = INT_MAX;
        for(int k = (i+1); k < j; k++){
            int ansMine = (values[i]*values[k]*values[j]);
            int ansLeft = minScoreHelper(values, i, k, dp);
            int ansRight = minScoreHelper(values, k, j, dp);
            int totalSum = (ansMine+ansLeft+ansRight);
            finalAns = min(finalAns, totalSum);
        }
        
        dp[i][j] = finalAns;
        return finalAns;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int** dp = new int*[values.size()];
        for(int i = 0; i < values.size(); i++){
            dp[i] = new int[values.size()];
            for(int j = 0; j < values.size(); j++){
                dp[i][j] = -1;
            }
        }
        
        return minScoreHelper(values, 0, values.size()-1, dp);
    }
};