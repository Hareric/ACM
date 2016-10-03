class WordDictionary {
public:
    vector<vector<string> > s_v;  
    vector<int> b_v;  // b_v[0]=3 for s_v[0] is the vector for word's length is 3
    // Adds a word into the data structure.
    void addWord(string word) {
        int i=0;
        for (i; i<b_v.size(); i++){
            if(b_v[i] == word.length()){
                break;
            }
        }
        if(i<b_v.size()){
            s_v[i].push_back(word);
        }
        else{
            b_v.push_back(word.length());
            vector<string> temp (1, word);
            s_v.push_back(temp);
        }
    }
    
    int isIn(string word){
        for (int i=0; i<b_v.size(); i++){
            if(b_v[i] == word.length()){
                return i;
            }
        }
        return -1;
    }

    bool comp(string word, string pattern){
        for(int i=0; i<pattern.length(); i++){
            if(word[i]!=pattern[i] && pattern[i]!='.'){
                return false;
            }
        }
        return true;
    }
    
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string pattern) {
        int t = isIn(pattern);
        if (t==-1){
            return false;
        }
        else{

            for(int i=0; i<s_v[t].size(); i++){
                if (comp(s_v[t][i], pattern)){
                    return true;
                }
            }
        }
        return false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
