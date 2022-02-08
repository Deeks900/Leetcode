class Solution {
public:
    void solveSudokuH(vector<vector<char>>& board, vector<vector<int>>& arr, vector<int>&rows,vector<int>& cols,vector<vector<int>>& grid,int i,int j){
    if(j == 9){
        j = 0;
        i = i+1;
    }

    //Base Case
    if(i == 9){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(arr[i][j] != 0){
                    board[i][j] = (arr[i][j]+'0');
                }
                else{
                    board[i][j] = '.';
                }
            }
        }
        return;
    }

   //Recursion Calls
   //means cell is not empty
   if(arr[i][j] != 0){
       solveSudokuH(board, arr, rows, cols, grid, i, j+1);
   }
   //means cell is empty
   else{
       //In this cell numbers from 1 to 9 have a chance to come
       for(int num = 1; num <= 9; num++){
           //Check if that number is unique in row, col and grid
           if(
               ((rows[i]&(1<<num)) == 0) && 
                ((cols[j]&(1<<num)) == 0) &&
                (grid[i/3][j/3]&(1<<num)) == 0

           ){
               rows[i] = (rows[i]|(1<<num));
               cols[j] = (cols[j]|(1<<num));
               grid[i/3][j/3] = (grid[i/3][j/3]|(1<<num));
               arr[i][j] = (num);
               solveSudokuH(board, arr, rows, cols, grid, i, j+1);
               arr[i][j] = 0;
               grid[i/3][j/3] = (grid[i/3][j/3]&(~(1<<num)));
               rows[i] = (rows[i]&(~(1<<num)));
               cols[j] = (cols[j]&(~(1<<num)));
           }
       }
   }
   
}



    void solveSudoku(vector<vector<char>>& board) {
         vector<int>rows(9,0);
    vector<int>cols(9,0);
    vector<vector<int>>grid(3,vector<int>(3,0));
        vector<vector<int>>arr(9,vector<int>(9,0));
        
        for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            
            if(board[i][j] != '.'){
                int digit = (board[i][j]-'0');
                arr[i][j] = digit;
            rows[i]|=(1<<digit);
            cols[j]|=(1<<digit);
            grid[i/3][j/3]|=(1<<digit);
            }
            
            if(board[i][j] == '.')
                arr[i][j] = 0;
            
        }
    }
    
        solveSudokuH(board, arr, rows,cols,grid,0,0);
    }
};