class Solution {
    public int maxChunksToSorted(int[] arr)
    {
        final int len = arr.length;
        final int max_from_Left[] = new int[len];
        final int min_from_right[] = new int[len];
        
        //record the maximum of the right sub array
        int myMax = arr[0];
        max_from_Left[0] = arr[0];
        
        
        int myMin = arr[len-1];
        min_from_right[len-1] = arr[len-1];
        
        for(int i = 1; i < len; i++)
        {
        	if(arr[i] > myMax)
        	{
        		myMax = arr[i];
        	}
        	max_from_Left[i] = myMax;
        }
        
        int ans = 1;
        
        for(int i = len-2; i >= 0; i--)
        {
        	//record the minimum of the left sub array
        	if(arr[i] < myMin)
        	{
        		myMin = arr[i];
        	}
        	min_from_right[i] = myMin;
        	if(max_from_Left[i] <= min_from_right[i+1])
        	{
        		ans++;
        	}
        }
        return ans;
 
    }
}