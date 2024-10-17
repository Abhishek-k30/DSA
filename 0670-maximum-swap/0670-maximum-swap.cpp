class Solution {
public:
    int maximumSwap(int num) {
        string t = to_string(num);
        
        for(int i = 0; i<t.size()-1; i++){
            char c = t[i];
            int idx = i;
            char sw = c;
            for(int j = t.size()-1; j>i; j--){
                if(t[j]>c){
                    if(t[j]>sw){
                        idx = j;
                        sw = t[j];
                    }
                }
            }
            
            if(idx!=i){
                swap(t[i], t[idx]);
                return stoi(t);
            }
        }
        
        return num;
    }
};