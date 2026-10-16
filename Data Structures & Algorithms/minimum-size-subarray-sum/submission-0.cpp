class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int mincount = INT_MAX;
        int left = 0;
        for(int right=0; right<nums.size(); right++)
        {
            sum += nums[right];
        
            while(sum >= target)
            {
                mincount = min(mincount, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return mincount == INT_MAX ? 0 : mincount;
    }
};