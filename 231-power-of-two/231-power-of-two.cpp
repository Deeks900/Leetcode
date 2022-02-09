class Solution {
public:
    bool isPowerOfTwo(int n) {
         if(n == 0){
            return false;
        }
        long x = n;
       
        if((x&(x-1)) == 0){
            return true;
        }
        return false;
    }
};