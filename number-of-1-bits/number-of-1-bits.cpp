class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> temp= n;
        return temp.count();
    }
};