class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        unordered_map<int, vector<pair<int, int>>> coord;
        int j = 0;
        for(int i = 0; i < artifacts.size(); i++){
            pair<int, int> temp1 = {artifacts[i][0], artifacts[i][1]};
            pair<int, int> temp2 = {artifacts[i][2], artifacts[i][3]};
            coord[j].push_back(temp1);
            coord[j].push_back(temp2);
            j++;
        }
        
        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        for(auto i: dig){
            visited[i[0]][i[1]] = 1;
        }
        
        for(auto it=coord.begin(); it != coord.end(); it++){
            pair<int, int> start = it->second[0];
            pair<int, int> end = it->second[1];
            int index = it->first;
            bool flag = true;
            
            for(int i = start.first; i <= end.first; i++){
                for(int j = start.second; j <= end.second; j++){
                    if(!visited[i][j]){
                        flag = false;
                    }
                    if(!flag)
                        break;
                }
                 if(!flag)
                        break;
            }

           if(flag){
               ans++;
           } 
            
            }
        return ans;
    }
};