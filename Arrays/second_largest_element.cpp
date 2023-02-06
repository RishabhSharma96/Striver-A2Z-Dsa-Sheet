class Solution
{
public:
    // Function returns the second
    // largest elements
    int print2largest(int arr[], int n)
    {
        int f = arr[0];
        int s = -1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > f)
            {
                s = f;
                f = arr[i];
            }
            if (arr[i] > s && arr[i] < f)
                s = arr[i];
        }
        return s;
    }
};