class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for(auto x : nums)
            s.insert(x);
        
        int maxcount = 0;
        for(auto x : s)
        {
            // x is the starting element of the sequence
            if(s.find(x-1) == s.end())
            {
                int currentcount = 1;
                int curr = x;

                while(s.find(curr + 1) != s.end())
                {
                    currentcount++;
                    curr++;
                }

                maxcount = max(maxcount, currentcount);
            }
        }
        return maxcount;
    }
};