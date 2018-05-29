/*
 *
 https://leetcode.com/problems/house-robber/
 *
 */

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

int rob(vector<int>& nums) {
    if (nums.empty()){return 0;}
    if (nums.size()<3){return *max_element(nums.begin(),nums.end());}
    int max_cur = nums[1];
    int max_prev = nums[0];
    for (int i=2; i<nums.size();i++){
        int new_max = max(max_prev+nums[i],max_cur);
        max_prev = max(max_cur, max_prev);
        max_cur = new_max;
    }
    return max(max_cur,max_prev);
}

int main(){
    vector<int> houses = {1,2,3,1};
    cout << rob(houses) << endl;
    houses = {2,7,9,3,1};
    cout << rob(houses) << endl;
    houses = {2,1,1,2};
    cout << rob(houses) << endl;
    return 0;
}