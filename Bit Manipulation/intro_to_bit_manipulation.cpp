class Solution
{
public:
    int get(int num, int i)
    {
        return (num >> (i - 1)) & 1;
    }

    long long set(int num, int i)
    {
        return ((1 << (i - 1)) | num);
    }

    int clear(int num, int i)
    {
        return (~(1 << (i - 1)) & num);
    }

    void bitManipulation(int num, int i)
    {
        cout << get(num, i) << " " << set(num, i) << " " << clear(num, i);
    }
};