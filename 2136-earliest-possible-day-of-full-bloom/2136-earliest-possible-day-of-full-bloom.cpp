class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size();
        vector<pair<int, int>> time(n);
        for(int i = 0; i < n; i++){
            time[i].first = growTime[i];
            time[i].second = plantTime[i];
        }
        
        
        //Sort it
        sort(time.begin(), time.end());
        int res = 0;
        for(auto [g, p]:time){
            res = max(res, g)+p;
        }
        
        return res;
    }
};