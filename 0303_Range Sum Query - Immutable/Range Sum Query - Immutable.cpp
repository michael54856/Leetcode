class NumArray {
public:
    vector<int> myNum;
    NumArray(vector<int>& nums)
    {
        myNum = nums;
        int sum = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            sum += nums[i];
            myNum[i] = sum;
        }
    }

    int sumRange(int left, int right)
    {
        if(left == 0)
        {
            return myNum[right];
        }
        return myNum[right]-myNum[left-1];
    }
};