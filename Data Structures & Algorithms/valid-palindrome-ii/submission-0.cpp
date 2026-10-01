class Solution {
public:
    bool ispalindrome(string &s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] == s[end])
            {
                start++, end--;
            }
            else
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start = 0, end = s.size() - 1;

        while(start < end)
        {
            if(s[start] == s[end])
            {
                start++, end--;
            }
            else
            {
                // check deleting s[start]
                bool flag1 = ispalindrome(s, start + 1, end);
                // check deleting s[end]
                bool flag2 = ispalindrome(s, start, end - 1);
                
                return flag1 || flag2;
            }
        }
        return true;
    }
};