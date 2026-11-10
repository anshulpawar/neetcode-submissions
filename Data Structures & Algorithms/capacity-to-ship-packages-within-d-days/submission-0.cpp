class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity)
    {
        int daysNeeded = 1;
        int currentWeight = 0;

        for(int i=0; i<weights.size(); i++)
        {
            if(currentWeight + weights[i] > capacity)
            {
                daysNeeded++;
                currentWeight = weights[i]; 
            }
            else
                currentWeight += weights[i];
        }

        return daysNeeded <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low < high)
        {
            // least capacity of the ship
            int mid = low + (high - low) / 2;

            if(canShip(weights, days, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return high;
    }
};