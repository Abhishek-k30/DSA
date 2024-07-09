class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
         double n = customers.size();
         double timeOfPrepare = 0;
        double waitingTime =  0;
        
        for(int i = 0; i<n; i++){
            if(customers[i][0]>timeOfPrepare){
                timeOfPrepare=customers[i][0] + customers[i][1];
                waitingTime+= customers[i][1];
            }
            else{
                
                timeOfPrepare+=customers[i][1];
                if(customers[i][0] >= timeOfPrepare){
                    waitingTime+=customers[i][1];
                    timeOfPrepare=customers[i][0] + customers[i][1];
                }
                else {
                    waitingTime+=timeOfPrepare-customers[i][0];
                }
            }
            
            cout<<waitingTime <<" ";
        }
        
        cout<<endl;
        return waitingTime/n;
         
    }
};