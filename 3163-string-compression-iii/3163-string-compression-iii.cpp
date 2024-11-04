class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        char c = word[0];
        int len = 0;
        for(int i = 0; i<word.size(); i++){
            if(word[i]==c){
                if(len==9){
                    comp+= (len + '0');
                    comp+=c;
                    len = 1;
                }
                else len++;
            }
            else {
                comp+= (len + '0');
                comp+=c;
                len = 1;
                c = word[i];
            }
        }
         comp+= (len + '0');
         comp+=c;
        
        return comp;
    }
};