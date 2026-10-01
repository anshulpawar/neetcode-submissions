class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // check if 1 exist or not
        bool one = false;
        for(int x : nums)
        {
            if(x == 1)
                one = true;
        }
        if(!one)
            return 1;

        // convert all invalid number (x <= 0 & x > n) to 1
        for(int &x : nums)
        {
            if(x <= 0 || x > n)
                x = 1;
        }

        // mark the index to negative for a number if it exist
        for(int i=0; i<n; i++)
        {
            int x = abs(nums[i]);
            nums[x - 1] = -abs(nums[x - 1]);
        }

        // if any number is still positives it's index + 1 is the answer
        for(int i=0; i<n; i++)
        {
            if(nums[i] > 0)
                return i + 1;
        }

        // if all elements are -ve means n + 1 is the answer
        return n + 1;
    }
};