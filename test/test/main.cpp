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
#include <map>
#include <set>
using namespace std;


bool searchMatrixDivideAndConquer(vector<vector<int>>& matrix, int row_st, int row_ed, int col_st, int col_ed, int target){
    int res = false;

    //corner cases
    if (row_st>row_ed||col_st>col_ed) return res;

    //common cases
        //-> calculate case
    if (row_st == row_ed && col_st==col_ed){
        if(target == matrix[row_st][col_st]) res = true;
        else return false;
    }
        //-> split cases
    int row_mid = (row_st+row_ed)/2;
    int col_mid = (col_st+col_ed)/2;
    bool splitLfUp = searchMatrixDivideAndConquer(matrix, row_st, row_mid, col_st, col_mid, target);
    bool splitLtDown = searchMatrixDivideAndConquer(matrix, row_mid+1, row_ed, col_st, col_mid, target);
    bool splitRtUp = searchMatrixDivideAndConquer(matrix, row_st, row_mid, col_mid+1, col_ed, target);
    bool splitRtDown = searchMatrixDivideAndConquer(matrix, row_mid+1, row_ed, col_mid+1, col_ed, target);
    return splitLfUp || splitRtUp || splitLtDown || splitRtDown;


}



bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rowSize = matrix.empty()? -1: matrix.size()-1;
    int colSize = matrix.empty()? -1: matrix[0].size()-1;
    bool res = searchMatrixDivideAndConquer(matrix, 0, rowSize, 0, colSize, target);
    return res;
}

int main(int argc, const char * argv[]) {

    vector<vector<int>> nums = {};
    int val = INT_MAX;
    bool res =  searchMatrix(nums, val);
    cout<<res<<endl;
    return 0;

}
