class Solution {
public:
    void printLexographic(int i, int n, vector<int>& result){
    if(i > n){
        return;
    }
    
   result.push_back(i);
    for(int j = 0; j < 10; j++){
        printLexographic(i*10+j, n, result);
    }
}
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int i = 1; i < 10; i++){
        printLexographic(i, n, result);
    }
        return result;
    }
};