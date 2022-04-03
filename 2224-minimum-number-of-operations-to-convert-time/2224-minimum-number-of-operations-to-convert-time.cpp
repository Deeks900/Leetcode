class Solution {
public:
    int convertTime(string current, string correct) {
        string hrCurr = current.substr(0, 2);
        string hrCorr = correct.substr(0, 2);
        string minCurr = current.substr(3);
        string minCorr = correct.substr(3);
        
        int currMin = (stoi(hrCurr)*60+stoi(minCurr));
        int corrMin = (stoi(hrCorr)*60+stoi(minCorr));
        int diff = (corrMin-currMin);
        
        int count = 0;
        for(auto i: {60,15,5,1}){
           count += diff/i;
           diff %= i;
        }
        return count;
    }
};