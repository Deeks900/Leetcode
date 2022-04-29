class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        for(auto i: tasks){
            freq[i] += 1;
        }
        
        int ans = 0;
        bool flag = true;
        for(auto i: freq){  
            if(i.second == 1){
                flag = false;
                break;
            }
            ans += ceil(i.second/3.0);
        }
        
        if(ans == 0 || flag == false){
            return -1;
        }
        return ans;
        
    }
};