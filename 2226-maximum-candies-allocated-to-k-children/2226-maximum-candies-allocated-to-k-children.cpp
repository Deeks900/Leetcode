class Solution {
public:
    bool isPossible(vector<int>& candies, long long k, int mid){
        long long count = 0;
        for(auto i: candies){
            if(i >= mid){
                int temp1 = i/mid;
                count += temp1;
            }
        }
        
        if(count >= k){
            return true;
        }
        else{
            return false;
        }
        
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int maxAns = INT_MIN;
        for(auto i: candies){
            maxAns = max(maxAns, i);
        }
        int high = maxAns;
        int ans = 0;
        while(low <= high){
            int mid = (low+(high-low)/2);
            if(isPossible(candies, k, mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};