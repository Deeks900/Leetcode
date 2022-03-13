class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        for(auto i: dig){
            visited[i[0]][i[1]] = 1;
        }
        
        for(int i = 0; i < artifacts.size(); i++){
            pair<int, int> start = {artifacts[i][0], artifacts[i][1]};
            pair<int, int> end = {artifacts[i][2], artifacts[i][3]};
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