class Solution {
public:
    int minFlips(int a, int b, int c) {
        return __builtin_popcount((a | b) ^ c) + __builtin_popcount(a & b & ((a | b) ^ c));

    }
};
// popcount returns the number of set bits