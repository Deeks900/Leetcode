class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        //unordered map to store mask and indexes of pepople making that map
        unordered_map<int, vector<int>> dp;
        vector<int> temp;
        dp.reserve(1 << req_skills.size()); 
        dp[0] = temp;
        //unordered map to store skills against a particular integer
        unordered_map<string, int> skillsIndex;
        for(int i = 0; i < req_skills.size(); i++){
            skillsIndex[req_skills[i]] = i;
        }
        
        //Traversing the people array
        for(int j = 0; j < people.size(); j++){
            int curSkill = 0;
            //Traversing the skills of each people
            for(auto k: people[j]){
                curSkill |= (1 << skillsIndex[k]);
            }
            
            //Check the combination of this currSkill Mask and all others in dp map
            for(auto i=dp.begin(); i!=dp.end(); i++){
                int combo = (i->first|curSkill);
                //If this combo not existing already in map or it existing with larger number of people 
                if(dp.find(combo) == dp.end() || dp[combo].size()>(dp[i->first].size()+1)){
                    dp[combo] = i->second;
                    dp[combo].push_back(j);
                }
            }
        }
        return dp[(1<<(req_skills.size()))-1];
        
    }
};