
class Solution
{
public:
    int minBitFlips(int start, int goal)
    {

        int flips = 0;

        while (start != 0 || goal != 0)
        {
            int bit_start = start & 1;
            int bit_goal = goal & 1;
            // cout<<bit_start <<" "<<bit_goal<<endl;
            if (bit_start != bit_goal)
            {
                flips++;
            }

            start = start >> 1;
            goal = goal >> 1;
        }
        return flips;
    }
};