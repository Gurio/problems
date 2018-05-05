/*
 *
 https://leetcode.com/problems/container-with-most-water/description/
 *
 */

#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

int maxArea(vector<int>& heights) {
    int i=0;
    int j=heights.size()-1;
    int max_area = 0;
    while (j>i){
        int min_h = min (heights[i], heights[j]);
        int area = min_h * (j-i);
        cout << i << " " << j << " " << min_h << " " << area << " " << max_area << " " << endl; 
        max_area = max(max_area, area);
        while (heights[i]<=min_h){i++;}
        while (heights[j]<=min_h){j--;}
    }
    return max_area;
}

int main(){
    vector<int> input = {3, 1, 2, 4, 5};
    int result = maxArea(input);
    cout << result << endl; 
    input = {1,2,1};
    result = maxArea(input);
    cout << result << endl; 
    return 0;
}