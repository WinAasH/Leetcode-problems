class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num)
        {
            sum += num % 10;
            num = num / 10;
        }
        int res = sum % 9;
        return (res == 0) ? (sum == 0) ? 0 : 9 : res;
        
    }
};