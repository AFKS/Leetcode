# 169 Majority Element
## Description
> Given an array of size n, find the majority element. **The majority element 
> is the element that appears more than ⌊ n/2 ⌋ times**.
>
> You may assume that the array is non-empty and the majority element always 
> exist in the array.

向下取整:![](https://wikimedia.org/api/rest_v1/media/math/render/svg/f0ec449ec02f0c040dba1a7ca56c5fa73550459d)

## Solution
- **Divide and Conquer**
- Bit Manipulation
- *Array*

### Divide and Conquer
1. C++
```c++
class Solution {
public:
    
    void divideConquor(vector<int>& nums, int st, int ed, map<int,int>& imap, int& res){
        if (st>ed) return;
        
        if (st == ed){
            ++imap[nums[st]];
            if (imap[nums[st]]>nums.size()/2)
                res = nums[st];  
            return;
        }
        int mid = (st+ed)/2;
        divideConquor(nums,st,mid,imap,res);
        divideConquor(nums,mid+1,ed,imap,res);
    }      
        
    
    int majorityElement(vector<int>& nums) {
        if(nums.empty()) return 0;
        map<int,int> imap;
        int res = nums[0];
        divideConquor(nums,0,nums.size()-1,imap,res);
        return res;
    }
};
```
- Complexity

### Bit Manipulation

1. C++


2. Python



