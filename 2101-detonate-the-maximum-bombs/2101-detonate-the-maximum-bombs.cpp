class Solution {
public:
    int dfs(int i, vector<vector<int>> &al, bitset<100> &detonated) {
    if (!detonated[i]) {
        detonated[i] = true;
        for (int j : al[i])
            dfs(j, al, detonated);
    }
    return detonated.count();
   }
    
    int maximumDetonation(vector<vector<int>>& bs) {
    int res = 0, sz = bs.size();
    vector<vector<int>> al(bs.size());
    for (int i = 0; i < sz; ++i) {
        long long x = bs[i][0], y = bs[i][1], r2 = (long long)bs[i][2] * bs[i][2];
        for (int j = 0; j < bs.size(); ++j)
            if ((x - bs[j][0]) * (x - bs[j][0]) + (y - bs[j][1]) * (y - bs[j][1]) <= r2)
                al[i].push_back(j);
    }
    for (int i = 0; i < sz && res < sz; ++i)
        res = max(dfs(i, al, bitset<100>() = {}), res);
    return res;
 }
};

// Understood. code once again after 1 day. Here the basic idea is we are making a graph of connected componenets where the points that will be connected if it share space with our choosed circle.  And for this we will use a condition that it will be only possible if the distance of the center of the cirle from our choosed circle is less than r^2( that is x^2+y^2<=r^2).  AFTER THAT OUR PROBLEM WILL TURN INTO STANDARD PROBLEM OF GRAPH THAT IS FIND THE MAXIMUM NUMBER OF CONNECTED COMPONENTS AND FOR THIS WE CAN USE DFS OR BFS.  TC=(N*M), SC=O(N*M); 
