class Solution {
public:
    int findComplement(int num) {
        long long bitSize = log2(num)+ 1;
        long long xorValue = (1LL<<(bitSize))-1;
        return num^xorValue;
    }
};