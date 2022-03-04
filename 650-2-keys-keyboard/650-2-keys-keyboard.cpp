class Solution {
public:
    int keysHelper(int n, int countAScreen, int copyStatus, int pasteCount){
        //Base Case
        if(countAScreen > n){
            return 10001;
        }
        
        if(countAScreen == n){
            return 0;
        }
    
        //Recursive Calls
        if(copyStatus == 0){
            return 1+keysHelper(n, countAScreen, 1, countAScreen);
        }
            int op1 = 1+keysHelper(n, countAScreen+pasteCount, copyStatus, pasteCount);
            int op2 = 1+keysHelper(n, countAScreen+pasteCount, 0, 0);
            return min(op1, op2);
       
        
    }
    
    int minSteps(int n) {
        return keysHelper(n, 1, 0, 0);
    }
};