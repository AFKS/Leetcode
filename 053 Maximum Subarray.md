# 053 Maximum Subarray (Template)

## Description
> Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
> 
> For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
> the contiguous subarray [4,-1,2,1] has the largest sum = 6.

## Solution
- **Divide and Conquer**
- Dynamic Programming

### Divide and Conquer
1. C++

```c
class Solution {
public:
    int midPartMaxArray(vector<int>& nums, int st, int ed, int midSpot){
        //corner case
        if (st>ed) return INT_MIN;
        else if (st == ed) return nums[st];
        //common case
        int lfDirMaxArray, rtDirMaxArray;
        int lfDirSumArray, rtDirSumArray;
        lfDirMaxArray = rtDirMaxArray = INT_MIN;
        lfDirSumArray = rtDirSumArray = 0;
        //midSpot -> ed
        for (int i = midSpot; i<=ed; ++i){
            rtDirSumArray+=nums[i];
            rtDirMaxArray = rtDirSumArray>rtDirMaxArray?rtDirSumArray:rtDirMaxArray;
        }
        //midSpot -> st
        for (int i = midSpot; i>=st; --i){
            lfDirSumArray+=nums[i];
            lfDirMaxArray = lfDirSumArray>lfDirMaxArray?lfDirSumArray:lfDirMaxArray;
        }
        return lfDirMaxArray+rtDirMaxArray-nums[midSpot];
    }
    
    int maxSubArray(vector<int>& nums, int st, int ed){
        //corner case
        if (st>ed) return INT_MIN;
        if (st==ed) return nums[st];
        //common case
        int midSpot = (st+ed)/2;
        int lfPartMaxSubVal = maxSubArray(nums, st, midSpot-1);
        int rtPartMaxSubVal = maxSubArray(nums, midSpot+1,ed);
        int midPartMaxSubVal = midPartMaxArray(nums,st,ed,midSpot);
        return max(max(lfPartMaxSubVal,rtPartMaxSubVal),midPartMaxSubVal);
    }
    
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums,0,nums.size()-1);
    }
};
```

- Complexity

### Dynamic Programming
3. 