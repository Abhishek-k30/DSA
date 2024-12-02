class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int count = 1;
        string temp = "";
        
        for(auto & word : sentence){
            
            if(word == ' '){
                count++;
                temp = "";
            }
            else temp+= word;
            
            if(temp == searchWord){
                return count;
            }
        }
        
        return -1;
    }
};