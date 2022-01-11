class Solution {
public:
    int getGold(vector<vector<int>>& grid, int n, int m, int x, int y){
        //Base Case
        if(x < 0 || x >= n || y < 0 || y >= m){
            return 0;
        }
    
        if(grid[x][y] == 0){
         return 0;
        }
        //Recursive Calls
        int temp = grid[x][y];
        grid[x][y] = 0;
        int ans1 = getGold(grid, n, m, x-1, y);
        int ans2 = getGold(grid, n, m, x+1, y);
        int ans3 = getGold(grid, n, m, x, y-1);
        int ans4 = getGold(grid, n, m, x, y+1);
        grid[x][y] = temp;
        
        int finalAns = 0;
        int temp1 = max(ans1, ans2);
        int temp2 = max(ans3, ans4);
        int temp3 = max(temp1, temp2);
        finalAns = (max(finalAns, temp3)+grid[x][y]);
        return finalAns;
    
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
    
        int finalAns = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    int ans = getGold(grid, n, m, i, j);
                    finalAns = max(finalAns, ans);
                }
                    
            }
        }
        return finalAns;
    }
};