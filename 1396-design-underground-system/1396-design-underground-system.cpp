class UndergroundSystem {
public:
//     map<string,  map<int, int>> checkin;
//     map<string,  map<int, int>> checkout;
//     UndergroundSystem() {
        
//     }
    
//     void checkIn(int id, string stationName, int t) {
//         checkin[stationName][id]=t;
//     }
    
//     void checkOut(int id, string stationName, int t) {
//         checkout[stationName][id]=t;
//     }
    
//     double getAverageTime(string startStation, string endStation) {
//         auto it1=checkin[startStation];
//         auto it2=checkout[endStation];
        
//         double sum1=0, sum2=0;
//         double cnt=0;
//         for(auto it: it1){
//             double a=it.second;
//             double b=it2[it.first];
//              if(a>0 && b>0){
//                  sum1+=a;
//                  sum2+=b;
//                  cnt++;
//              }
//         }
        
//         double ans=(sum2-sum1)/cnt;
//         return   ans ;
    
     unordered_map<int, pair<string, int>> checkInMap; // Uid - {StationName, Time}
    unordered_map<string, pair<double, int>> routeMap; // RouteName - {TotalTime, Count}
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn = checkInMap[id];
        checkInMap.erase(id); // Remove after using it which will not make HashTable big
            
        string routeName = checkIn.first + "_" + stationName;
        routeMap[routeName].first += t - checkIn.second;
        routeMap[routeName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + "_" + endStation;
        auto& route = routeMap[routeName];
        return route.first / route.second;
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */