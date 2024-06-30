class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int remove = 1;
        int cnt1 = 0, cnt2 = 0;
        
        int red1 = red, blue1 = blue;
        while(true){
            if(red1 - remove<0)
                break;
            red1-= remove;
            cnt1++;
            remove++;
            if(blue1 - remove<0)
                break;
            blue1-= remove;
            cnt1++;
            remove++;
        }
         red1 = red;
        blue1 = blue;
        remove = 1;
         while(true){
             if(blue1 - remove<0)
                break;
            blue1-= remove;
            cnt2++;
            remove++;
            if(red1 - remove<0)
                break;
            red1-= remove;
            cnt2++;
            remove++;
           
        }
        
        return max(cnt1, cnt2);
        
    }
};