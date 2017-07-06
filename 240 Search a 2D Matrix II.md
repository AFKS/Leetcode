# 240 Search a 2D Matrix II

## Description
> Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
> 
> Integers in each row are sorted in ascending from left to right.
> Integers in each column are sorted in ascending from top to bottom.
> For example,
> 
> Consider the following matrix:
> <pre>
> [
>   [1,   4,  7, 11, 15],
>   [2,   5,  8, 12, 19],
>   [3,   6,  9, 16, 22],
>   [10, 13, 14, 17, 24],
>   [18, 21, 23, 26, 30]
> ]
> </pre>
> Given target = 5, return true.
> Given target = 20, return false.

## Solution
- **Divide and Conquer**
- Binary Search


### Divide and Conquer
1. C++
```
class Solution {
public:
    bool searchMatrixDivideAndConquer(vector<vector<int>>& matrix, int row_st, int row_ed, int col_st, int col_ed, int target){
        //corner cases
        if (row_st>row_ed||col_st>col_ed||target<matrix[row_st][col_st]||target>matrix[row_ed][col_ed]) return false;

        //common cases
            //-> calculate case
        if (row_st == row_ed && col_st==col_ed)
            if(target == matrix[row_st][col_st]) return true;
            else return false;
        else{
            //-> split cases
            int row_mid = (row_st+row_ed)/2;
            int col_mid = (col_st+col_ed)/2;
            bool lfSplitUp = searchMatrixDivideAndConquer(matrix, row_st, row_mid, col_st, col_mid, target);
            bool lfSplitDown = searchMatrixDivideAndConquer(matrix, row_mid+1, row_ed, col_st, col_mid, target);
            bool rtSplitUp = searchMatrixDivideAndConquer(matrix, row_st, row_mid, col_mid+1, col_ed, target);
            bool rtSplitDown = searchMatrixDivideAndConquer(matrix, row_mid+1, row_ed, col_mid+1, col_ed, target);
            return lfSplitUp||lfSplitDown||rtSplitUp||rtSplitDown;
        }
    }
         
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.empty()? -1: matrix.size()-1;
        int colSize = matrix.empty()? -1: matrix[0].size()-1;
        return searchMatrixDivideAndConquer(matrix, 0, rowSize, 0, colSize, target);
    }
};
```

### Binary Search
