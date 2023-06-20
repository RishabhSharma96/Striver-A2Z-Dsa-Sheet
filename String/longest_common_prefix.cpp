class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = "", min_string = "";
        int min_length = INT_MAX;
        bool isMatch = false;

        for (int i = 0; i < strs.size(); i++)
        {
            if (min_length > strs[i].size())
            {
                min_length = strs[i].size();
                min_string = strs[i];
            }
        }

        for (int i = 0; i < min_length; i++)
        {
            char element = min_string[i];
            isMatch = true;
            for (int j = 0; j < strs.size(); j++)
            {
                if (element != strs[j][i])
                {
                    isMatch = false;
                }
            }
            if (isMatch)
            {
                prefix.push_back(element);
            }
            else
            {
                break;
            }
        }

        return prefix;
    }
};