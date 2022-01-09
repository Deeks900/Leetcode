class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        //Sorting the strings in startWord and storing them all in a set
        unordered_set<string> s;
        for(auto &i: startWords){
            sort(i.begin(), i.end());
            s.insert(i);
        }
        
        int res = 0;
        //Now check every substring of strings in target word
        for(auto &i: targetWords){
            sort(i.begin(), i.end());
            int n = i.size();
            for(int j = 0; j < n; j++){
                string temp = (i.substr(0, j)+i.substr(j+1));
                if(s.count(temp)){
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};