class Solution {
public:
    int largestSquareMatrix(vector<vector<char>>& matrix, int** mem, int n, int m, int row, int col){
    //Base Case
    if(row >= n || col >= m || matrix[row][col] == '0'){
        return 0;
    }
  if(mem[row][col] != -1){
        return mem[row][col];
    }
        
    //Recursive Calls
    int ans1 = largestSquareMatrix(matrix, mem, n, m, row, col+1);
    int ans2 = largestSquareMatrix(matrix, mem, n, m, row+1, col);
    int ans3 = largestSquareMatrix(matrix, mem, n, m, row+1, col+1);

    int finalAns = min(ans1, min(ans2, ans3));
         mem[row][col] = (finalAns+1);
    return (finalAns+1);
}

    int maximalSquare(vector<vector<char>>& matrix) {
        //Calling the function
    int finalAns = INT_MIN;
    int ans = 0;
    int n = matrix.size();
    int m = matrix[0].size();
       
   int** mem = new int*[n];
     for(int i = 0; i < n; i++){
         mem[i] = new int[m];
         for(int j = 0; j < m; j++){
             mem[i][j] = -1;
         }
     }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] != '0'){
               ans = largestSquareMatrix(matrix, mem, n, m, i, j); 
            }
            finalAns = max(finalAns, ans);
        }
    }
    
   return (finalAns*finalAns);
    }
};