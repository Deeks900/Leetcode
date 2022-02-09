class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0){
          int mask = (n&(-n));
           n -= mask;
            count++;
        }
        return count;
    }
};