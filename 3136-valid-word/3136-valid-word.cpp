class Solution {
public:
    bool isValid(string word) {
        vector<char> vowel={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        map<char, int> m;
        for(int i=0; i<10;i++)m[vowel[i]]++;
        vector<int> num={0,1,2,3,4,5,6,7,8,9};
        if(word.size()<3)return false;
        bool f1=false, f2=false, f3=false;
        for(int i=0; i<word.size(); i++){
            if(m.find(word[i])!=m.end()  )f1=true;
            if((word[i]-'0'<=9 && word[i]-'0'>=0) || isalpha(word[i]))f2=true;
            else return false;
            if( isalpha(word[i]) &&m.find(word[i])==m.end() )f3=true;
        }
        
        if(f1 && f2 && f3)return true;
        return false;
        
        
    }
};