class Solution {
public:
    bool isPalindrome(string s) {
        string palindrome = "";
        for(int i=0; i<s.size(); i++)
        {
            if(isalnum(s[i]))
                palindrome += tolower(s[i]);
        }

        int start = 0, end = palindrome.size() - 1;
        while(start <= end)
        {
            if(palindrome[start] == palindrome[end])
            {
                start++;
                end--;
            }
            else    
                return false;
        }
        return true;
    }
};
