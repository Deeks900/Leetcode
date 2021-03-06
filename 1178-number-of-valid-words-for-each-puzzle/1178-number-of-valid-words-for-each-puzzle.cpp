class Solution {
public:
    
    //This will be creating the bitmask 
    int createBitmask(string word){
        int mask = 0;
        for(auto c: word){
            int num = c-'a';
            mask = mask | (1 << num);
        }
        
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        //unordered map for words
        unordered_map<int, int> countWords;
        for(auto word: words){
            int mask = createBitmask(word);
            countWords[mask] += 1;
        }
        
        //we will store results in it
        vector<int> result;
        
        for(auto p: puzzles){
            
            //working on each puzzle
            int firstMask = 1 << (p[0]-'a');
            int maskPuzzle = createBitmask(p);
            int submask = maskPuzzle;
            int count = 0;
            
            
            //iterating through all the subsets of this puzzle
            while(submask){
                if(submask&firstMask && countWords.find(submask) != countWords.end()){
                    count += countWords[submask];
                }
                //one rightmost bit will be turned off and all digits to the right of this bit will be set.
                submask -= 1;
                //unset all the bits in the right of submask which are not set in the maskPuzzle
                submask = submask&maskPuzzle;   
            }
            
            //valid words for this puzzle has been found out
            result.push_back(count);
        }
        
        return result;
    }
};