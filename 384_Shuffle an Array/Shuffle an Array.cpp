class Solution {
public:
    vector<int> original;
    Solution(vector<int>& nums)
     {
        original = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        int len = original.size();
        vector<int> shiffleVector = original;
        for(int i = 1; i <= len; i++)
        {
            swap(shiffleVector[rand()%i], shiffleVector[i-1]);
        }
        return shiffleVector;
    }
};