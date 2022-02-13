class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        //This variable will store the final ans of this question
        int maxXor = 0;
        //This will be storing the prefixes 
        unordered_set<int> prefixes;
        int mask = 0;
        int maxPossible = 0;
        
        //Traversing the 32 bits of an integer
        for(int i = 31; i >= 0; i--){
            //mask for this bit
            mask = (mask|(1<<i));
            maxPossible = (maxXor|(1 << i));
            //Traversing the array elements
            for(int j = 0; j < nums.size(); j++){
                //Inserting the prefixes in the set
                prefixes.insert(nums[j]&mask);
            }
            
            //Now using the concept a^b = c then a^c= b
            for(auto i: prefixes){
                if(prefixes.find(maxPossible^i) != prefixes.end()){
                    //Update the maximum one
                    maxXor |= maxPossible;
                    break;
                }
            }
            //clear the prefixes set
            prefixes.clear();
        }
        return maxXor;
    }
};