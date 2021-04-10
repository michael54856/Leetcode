class Solution {
    public int maxChunksToSorted(int[] arr)
    {
        final int len = arr.length;
        final int temp[] = new int[len];
        
        for(int i  = 0; i < len; i++)
        {
        	temp[i] = arr[i];
        }
        
        Arrays.sort(temp);
        
        int ans = 0;
        
        long originalSum = 0;
        long sum = 0;
        
        for(int i = 0; i < len; i++)
        {
        	sum += temp[i];
        	originalSum += arr[i];
        	if(sum == originalSum)
        	{
        		ans++;
        	}
        }
        return ans;
    }
}