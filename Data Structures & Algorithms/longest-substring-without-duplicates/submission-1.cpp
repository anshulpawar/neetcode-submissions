class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char> dq;

        int maxcount = 0;
        for(int i=0; i<s.size(); i++)
        {  
            // if duplicate exist
            while(find(dq.begin(), dq.end(), s[i]) != dq.end())
            {
                dq.pop_front();
            }

            dq.push_back(s[i]);
            maxcount = max(maxcount, (int)dq.size()); // dq.size() does not return int it returns size_t so type case it
        }
        return maxcount;
    }
};
