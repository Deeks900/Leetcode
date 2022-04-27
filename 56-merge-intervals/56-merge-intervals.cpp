class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedAns;
        
        for(auto i: intervals){
            if(mergedAns.size() == 0 || mergedAns.back()[1] < i[0]){
               mergedAns.push_back(i); 
            }
            else{
                  mergedAns.back()[1] = max(mergedAns.back()[1], i[1]);
            }
        }
        return mergedAns;
    }
};