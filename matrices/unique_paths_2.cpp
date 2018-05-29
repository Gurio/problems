/*
 *
 https://leetcode.com/problems/unique-paths-ii
 *
 */

#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

/*
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty()){return 0;}
    vector<vector<int>> paths(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(),0));;
    paths[0][0] = 1;
    int res = 0;
    for (int i=0; i<obstacleGrid.size(); ++i){
        for (int j=0; j<obstacleGrid[i].size(); ++j){
            if (obstacleGrid[i][j]!=1){
                if (j){
                    paths[i][j] += paths[i][j-1];
                }
                if (i){
                    paths[i][j] += paths[i-1][j];
                }
            } else {
                paths[i][j] = 0;
            }
            res = paths[i][j];
        }
    }
    return res;
}


int main(){
    vector<vector<int>> input ={{0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 1, 0},
                                {0, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0}};
    
    int result = uniquePathsWithObstacles(input);
    cout << result << endl;
    input ={{0, 0, 0,},
            {0, 1, 0},
            {0, 0, 0}};
    result = uniquePathsWithObstacles(input);
    cout << result << endl; 
    input ={{0, 0, 0,},
            {0, 0, 0},
            {0, 0, 0}};
    result = uniquePathsWithObstacles(input);
    cout << result << endl;
    input ={{1}};
    result = uniquePathsWithObstacles(input);
    cout << result << endl;
    return 0;
}