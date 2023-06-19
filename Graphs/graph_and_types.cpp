// User function Template for C++
class Solution
{
public:
    long long count(int n)
    {
        long long v = (n * (n - 1)) / 2;
        return pow(2, v);
    }
};