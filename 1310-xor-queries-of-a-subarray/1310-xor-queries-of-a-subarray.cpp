class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
      vector<int> xorResult(arr.size(), 0);
      xorResult[0] = arr[0];
        
      for(int i = 1; i < arr.size(); i++){
          xorResult[i] = (arr[i]^xorResult[i-1]);
      }
      
        vector<int> ans;
      for(auto i: queries){
          int res = 0;
          if(i[0] != 0)
          res = xorResult[i[1]]^xorResult[i[0]-1];
          else
        res = xorResult[i[1]];
          
          ans.push_back(res);
      }
        return ans;
    }
};