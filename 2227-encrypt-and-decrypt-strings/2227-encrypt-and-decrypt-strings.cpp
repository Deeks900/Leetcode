class Encrypter {
public:
    //data members
    vector<char> keys;
    vector<string> values;
    vector<string> dictionary;
    unordered_map<char, int> keyIndex;
    unordered_map<string, vector<int>> valuesIndex;
    unordered_map<string, int> freq;
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        this->keys = keys;
        this->values = values;
        this->dictionary = dictionary;
        for(int i = 0; i < keys.size(); i++){
            keyIndex[keys[i]] = i;
        }
        for(int i = 0; i < values.size(); i++){
            valuesIndex[values[i]].push_back(i);
        }
        
        for(auto i: dictionary){
            string ans = encrypt(i);
            freq[ans] += 1;
        }
    }
   

    string encrypt(string word1) {
        string ans = "";
        for(auto i: word1){
            int index = keyIndex[i];
            string temp = values[index];
            ans += temp;
        }
        return ans;
    }
    
    int decrypt(string word2) {
       return freq[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */