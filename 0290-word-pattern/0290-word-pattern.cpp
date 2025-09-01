class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string Word = "";
        vector<string>Words;
        s+=' ';
        for(int i=0; i<s.length(); i++){
            if(s[i]==' '){
                Words.push_back(Word);
                Word = "";
            }
            else{
                Word+=s[i];
            }
        }
        if(pattern.length() != Words.size()) return false;
        unordered_map<char,string> chartoword;
        unordered_map<string,char> wordtochar;

        for(int i=0; i<pattern.size();i++){
            char ch = pattern[i];
            string w = Words[i];

            if(chartoword.contains(ch) && chartoword[ch] != w) return false;
            if(wordtochar.contains(w) && wordtochar[w] != ch) return false;
            
            chartoword[ch] = w;
            wordtochar[w] = ch;
        }
        return true;
    }
};