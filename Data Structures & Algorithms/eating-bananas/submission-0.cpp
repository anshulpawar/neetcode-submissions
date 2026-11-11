class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k)
    {
        long long hoursNeeded = 0;

        for(int i=0; i<piles.size(); i++)
        {
            hoursNeeded += (piles[i] + (long long)k - 1) / k;
        }

        return hoursNeeded <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());


        while(low < high)
        {
            int mid = low + (high - low) / 2;

            if(canEat(piles, h, mid))
                high = mid;
            else
                low = mid + 1;
        }
        // loop stops when low == high so we can return any low or high
        return high;
    }
};