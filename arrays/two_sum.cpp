/*
 *
 https://leetcode.com/problems/two-sum/
 *
 */
 
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

vector <int> twoSum (vector<int>& nums, int target){
    unordered_map<int,int> num_pos;
    for (size_t i = 0; i<nums.size(); i++){
        int desired_num = target - nums[i];
        int addend_idx = num_pos[desired_num];
        if (addend_idx != 0){
            return {addend_idx-1, i};
        }
        num_pos[nums[i]] = i+1;
    }
    return {0,0};
}

int main(){
    vector<int> input = {2,7,11,15};
    vector<int> result = twoSum(input, 9);
    for (std::vector<int>::const_iterator i = result.begin(); i != result.end(); ++i)
        cout << *i << ' '; 
    cout << endl;
    return 0;
}