class Solution {
public:
     bool checkStraightLine(vector<vector<int>>& coordinates) {
         double x0=coordinates[0][0], y0=coordinates[0][1];
         double x1=coordinates[1][0], y1=coordinates[1][1];
        
        // Initial slope
        double delx=(x1-x0); 
        double dely=(y1-y0);
         double slope=100000;
        if(delx!=0)slope=dely/delx;
        
      
        
        for(int i=2; i<coordinates.size(); i++){
             double xCoordinate=coordinates[i][0];
             double yCoordinate=coordinates[i][1];
            
             double currSlope=100000;
             if((xCoordinate-x1)!=0)currSlope=(yCoordinate-y1)/(xCoordinate-x1);
             
             if(currSlope!=slope)return false;
            
             x1=xCoordinate;
             y1=yCoordinate;
        }
        
        return true;
        
        
    }
};