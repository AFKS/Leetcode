//
//  main.cpp
//  test
//
//  Created by Rhino_mom on 2017-07-04.
//  Copyright © 2017 Rhino_mom. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int midPartMaxArray(vector<int>& nums, int st, int ed, int midSpot){
    if (st>ed) return 0;
    if (st==ed) return nums[st];
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
    if (st<ed) return 0;
    int midSpot = (st+ed)/2;
    int lfPartMaxSubVal = maxSubArray(nums, st, midSpot-1);
    int rtPartMaxSubVal = maxSubArray(nums, midSpot+1,ed);
    int midPartMaxSubVal = midPartMaxArray(nums,st,ed,midSpot);
    return max(max(lfPartMaxSubVal,rtPartMaxSubVal),midPartMaxSubVal);
}

int maxSubArray(vector<int>& nums) {
    if (nums.empty()) return 0;
    return maxSubArray(nums,0,floor(nums.size()/2));
}



int main(int argc, const char * argv[]) {
    
    vector<int> nums;
    nums= {-2};
    int res = maxSubArray(nums);
    cout << res;
    return 0;
}
