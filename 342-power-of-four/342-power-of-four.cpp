class Solution {
public:
    bool isPowerOfFour(int x) {
        if(x == 0){
        return false;
    }

long n = x;
   int fact = 0b10101010101010101010101010101010;
   
   //check if n is a power of 2
   if((n&(n-1)) != 0){
       return false;
   }

   if((fact&n) != 0){
       return false;
   }
   return true;
    }
};