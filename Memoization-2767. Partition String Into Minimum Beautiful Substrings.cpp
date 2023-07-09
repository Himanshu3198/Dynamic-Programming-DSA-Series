class Solution
{
    public:
//     checking power of 5
    bool isPower5(int num)
    {
            if (num == 0) return false;
            while (num > 1)
            {
                if (num % 5 != 0) return false;
                num /= 5;
            }
            return true;
        
    }
    int check(string s)
    {
//         convert the binary representation of number into a number
        std::bitset<32> bitsetNumber(s);
        unsigned long long number = bitsetNumber.to_ullong();
        return isPower5(number);
    }
    int solve(string s, int idx)
    {
        if (idx == s.size()) return 0;

        long long ans = LONG_MAX, res = 0 LL;
        string temp = "";
        for (int i = idx; i < s.size(); i++)
        {
            temp += s[i];
            if (temp[0] == '0') break; // dont include string startng with zero
            
            if (check(temp))  // if the longest substring is power of 5 then partitioned 
            {
                res = 1 L + solve(s, i + 1);
            }
            if (res != 0 and res < ans) ans = res;
        }
        return ans;
    }
    int minimumBeautifulSubstrings(string s)
    {

        int ans = solve(s, 0);
        if (ans >= INT_MAX) return -1; 
        return ans;
    }
};
