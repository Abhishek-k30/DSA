class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0]!=sentence.back())return false;
        char first;
        for(int i = 0; i<sentence.size(); i++){
            if(sentence[i]==' '){
                if(sentence[i-1]!=sentence[i+1])return false;
            }
        }
        return true;
    }
};