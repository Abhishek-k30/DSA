class Solution {
private:
    int powerCalculator(int num){
        int steps = 0;
        while(num!=1){
            if(num%2==0)
                num/=2;
            else num = 3*num + 1;
            
            steps++;
        }
        
        return steps;
    }
public:
    int getKth(int lo, int hi, int k) {
        vector<int> power(1001, 0);
        for(int i= 1; i<=1000; i++){
            power[i] = powerCalculator(i);
        }
        
        vector<pair<int, int>> sortedPower;
        for(int i = lo; i<=hi; i++){
            sortedPower.push_back({power[i], i});
        }
        
        sort(sortedPower.begin(), sortedPower.end());
        
        return sortedPower[k-1].second;
        
    }
};