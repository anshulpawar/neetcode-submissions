class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> freq;
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++)
            freq[nums[i]]++;

        for(auto x : freq)
        {
            if(x.second > n / 3)
                ans.push_back(x.first);
        }
        return ans;
    }
};