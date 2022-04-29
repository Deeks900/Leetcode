class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        //Maintain a map showing you the blooming or dooming day
        map<int, int> dayCount;
        for(auto i: flowers){
            dayCount[i[0]]+=1;
            dayCount[i[1]+1]-=1;
        }
        
        //Now put the total flower count till that day in map
        int sum = 0;
        for(auto it = dayCount.begin(); it != dayCount.end(); it++){
            sum += it->second;
            dayCount[it->first] = sum;
        }
        
        // for(auto it: dayCount){
        //     cout << it.first << " " << it.second << endl;
        // }
        //Now Travel the persons array
        vector<int> ans(persons.size(), 0);
        int idx = 0;
        for(auto pday:persons){
            //If that day is present in map
            if(dayCount.find(pday) != dayCount.end()){
                ans[idx++] = (dayCount[pday]);
            }
            //If that day is not present in map
            else{
                auto it = dayCount.lower_bound(pday);
                if(it != dayCount.begin()){
                    it--;
                    ans[idx++] = (it->second);
                }
                else{
                    ans[idx++] = 0;
                }
            }
        }
        return ans;
    }
};