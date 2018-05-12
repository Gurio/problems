/*
 *
 https://leetcode.com/problems/range-sum-query-2d-immutable
 *
 */

#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

/*
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
*/

vector<vector<int>> sums;

void NumMatrix(vector<vector<int>> matrix) {
    sums = move(matrix);
    for (int i=0; i<sums.size();i++){
        int row_sum=0;
        for (int j=0; j<sums[i].size(); j++){
            int left  = row_sum;
            int upper = i>0 ? sums[i-1][j] : 0;
            row_sum += sums[i][j];
            sums[i][j] = sums[i][j] + left + upper;
        }
    }
}

int sumRegion(int row1, int col1, int row2, int col2) {
    int upper_sum = row1>0 ? sums[row1-1][col2] : 0;
    int left_sum  = col1>0 ? sums[row2][col1-1] : 0;
    int upper_left_sum = row1>0 && col1>0 ? sums[row1-1][col1-1] : 0;
    return ( sums[row2][col2]
            -upper_sum
            -left_sum
            +upper_left_sum);
}

int main(){
    vector<vector<int>> input ={{3, 0, 1, 4, 2},
                                {5, 6, 3, 2, 1},
                                {1, 2, 0, 1, 5},
                                {4, 1, 0, 1, 7},
                                {1, 0, 3, 0, 5}};
    NumMatrix(input);
    for (auto row: sums){
        for (auto num: row){
            cout << num << ",\t";
        }
        cout << endl;
    }
    int result = sumRegion(2, 1, 4, 3);
    cout << result << endl; 
    result = sumRegion(1, 1, 2, 2);
    cout << result << endl; 
    result = sumRegion(1, 2, 2, 4);
    cout << result << endl; 
    return 0;
}